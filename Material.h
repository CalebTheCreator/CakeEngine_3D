#pragma once
#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Material
{
public:
	Material();
	~Material();

	bool LoadShaders(std::string vertexFileName, std::string fragmentFileName);

	void SetMatrices(glm::mat4& modelMatrix, glm::mat4);

protected:

	bool CheckShaderCompiled(GLint shader);
	int shaderProgram;

	int shaderModelMatrixLocation;
	int shaderInverseModelMatrixLocation;
	int shaderViewMatrixLocation;
	int shaderProjectionMatrixLocation;

	int shaderDiffuseColorLocation;
	int shaderEmissiveColorLocation;
	int shaderSpecularColorLocation;
	int shaderLightLocation;
	int shaderTexSamplerLocation;

	glm::vec3 emissiveColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	glm::vec3 lightPosition;

	unsigned int LoadTexture(std::string filename);

	unsigned int texture1;
};

