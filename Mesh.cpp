#include "Mesh.h"
#include <stdexcept>

const GLfloat positions[] = {
		0.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f
	};

Mesh::Mesh(int _type)
{
	glGenBuffers(1, &m_posVboId);
	if (!m_posVboId) throw std::runtime_error("Failed to allocate positions VBO");
	glBindBuffer(GL_ARRAY_BUFFER, m_posVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &m_vaoId);
	if (!m_vaoId) throw std::runtime_error("Failed to allocate VAO");
	glBindVertexArray(m_vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, m_posVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

GLuint Mesh::GetId()
{
	return m_vaoId;
}

int Mesh::GetVertexCount()
{
	return 3;
}
