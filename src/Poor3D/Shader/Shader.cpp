#include <Poor3D/Poor3D.h>
#include <cstdio>

using namespace Poor3D::Shader;

Shader::Shader(const char *vs, const char *fs)
{
	std::string vsCode=readFile(vs);
	std::string fsCode=readFile(fs);
	GLuint vsID=createShader(GL_VERTEX_SHADER, vsCode.c_str());
	GLuint fsID=createShader(GL_FRAGMENT_SHADER, fsCode.c_str());

	id=linkProgram(vsID, fsID);

	glDeleteShader(vsID);
	glDeleteShader(fsID);
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

bool Shader::setUniform(const char *name, float value) const
{
	GLint variable=glGetUniformLocation(id, name);
	if(variable!=-1)
	{
		glUniform1f(variable, value);
		return true;
	}

	return false;
}

bool Shader::setUniform(const char *name, const Poor3D::Math::Mat4 &value) const
{
	GLint variable=glGetUniformLocation(id, name);
	if(variable!=-1)
	{
		glUniformMatrix4fv(variable, 1, GL_TRUE, &value.data[0][0]);
		return true;
	}

	return false;
}

std::string Shader::readFile(const char *filename) const
{
	FILE *fp = fopen(filename, "rb");
	if(!fp)
		throw std::runtime_error("Cannot open file");

	fseek(fp, 0, SEEK_END);
	int size=ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *buffer = new char[size+1];
	fread(buffer, 1, size, fp);
	buffer[size]='\0';

	std::string result=buffer;
	delete [] buffer;

	fclose(fp);

	return result;
}

GLuint Shader::createShader(GLenum shaderType, const char *shaderCode) const
{
	GLuint shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &shaderCode, NULL);
	glCompileShader(shaderID);

	//check for errors
	GLint result = GL_FALSE;
	int infoLength;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLength);

	if(result == GL_FALSE)
	{
		std::string info;
		char *buffer = new char[infoLength+1];
		glGetShaderInfoLog(shaderID, infoLength, NULL, buffer);
		buffer[infoLength]='\0';
		info = buffer;
		delete [] buffer;
		throw std::runtime_error(std::string("Compile shader error: ")+ info);
	}

	return shaderID;
}

GLuint Shader::linkProgram(GLuint vs, GLuint fs) const
{
	GLuint program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);

	//check for errors
	GLint result = GL_FALSE;
	int infoLength;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLength);

	if(result == GL_FALSE)
	{
		std::string info;
		char *buffer = new char[infoLength+1];
		glGetProgramInfoLog(program, infoLength, NULL, buffer);
		buffer[infoLength]='\0';
		info = buffer;
		delete [] buffer;
		throw std::runtime_error(std::string("Link shaders error: ")+ info);
	}

	return program;
}
