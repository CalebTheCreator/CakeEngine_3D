#pragma once
#include <GL/glew.h>
#include "ShaderType.h"

struct Shader
{
	Shader();
	Shader(ShaderType sT);
	Shader(ShaderType sT, struct GameObject g);
	~Shader();
	void CreateVertexShader();
	void CreateFragmentShader();
	void CreateProgramId();
	GLuint GetProgramId() { return programId; }

private:
	const GLchar* vertexShaderSrc;
	const GLchar* fragmentShaderSrc;

	GLuint vertexShaderId;
	GLuint fragmentShaderId;
	GLuint programId;

	GLint success = 0;
};

