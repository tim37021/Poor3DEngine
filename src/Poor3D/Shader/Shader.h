#ifndef SHADER_SHADER_H_
#define SHADER_SHADER_H_

#include <string>
#include <Poor3D/Math/Math.h>

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

				bool setUniform(const char *, float) const;
				bool setUniform(const char *, const Poor3D::Math::Mat4 &) const;
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
