#pragma once
#include <GL/glew.h>

struct Mesh
{
	Mesh(int type);
	GLuint GetId();
	int GetVertexCount();

private:
	GLuint m_vaoId;
	GLuint m_posVboId;
};

