#pragma once
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Mesh
{
public:
	Mesh();
	~Mesh();
	void LoadOBJ(std::string filename);
	void Draw();

protected:
	GLuint VertexArrayObject;
	unsigned int numVertices;

};

