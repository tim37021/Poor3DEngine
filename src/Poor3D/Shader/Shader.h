#ifndef SHADER_SHADER_H_
#define SHADER_SHADER_H_

#include <string>

namespace Poor3D
{
	namespace Shader
	{
		class Shader
		{
		public:
			Shader(const char *vs, const char *fs);
			~Shader();

			void bind() const
				{ glUseProgram(id); }
			GLuint getID() const
				{ return id; }
		private:
			GLuint id;
			std::string readFile(const char *filename) const;
			GLuint createShader(GLenum shaderType, 
				const char *shaderCode) const;
			GLuint linkProgram(GLuint vs, GLuint fs) const;
		};
	}
}

#endif