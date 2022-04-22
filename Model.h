#pragma once
#include <wavefront/wavefront.h>
#include <GL/glew.h>

struct Model
{
	Model(){}
	Model(const char* mSrc);
	~Model();
	WfModel GetModelInUse() { return ModelInUse; }
	GLuint GetVAOId() { return ModelInUse.vaoId; }
	GLuint GetTextureId() { return ModelInUse.textureId; }
	GLuint GetVertexCount() { return ModelInUse.vertexCount; }

private:
	
	WfModel ModelInUse = {0};
};

