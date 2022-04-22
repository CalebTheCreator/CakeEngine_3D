#pragma once
#define SDL_MAIN_HANDLED
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <stb_image.h>

#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "Program.h"
#include "RenderTexture.h"
#include "Mesh.h"
#include "ShaderType.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	Window window;
	//Shader shader = Shader(ShaderType::Diffuse);
	Shader shader;
	Model mike1("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	Model mike2("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	Model mike3("models/mike-wazowski/source/Mike Wazowski/Mike.obj");

	GLint projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	GLint modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");

	bool quit = false;
	float angle = 0;

	rTex::RenderTexture renderer(256, 256);

	
	while (quit == false)
	{
		SDL_Event evt;
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glUseProgram(shader.GetProgramId());

		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(
			glm::radians(45.0f), (float)window.GetWindowHeight() / (float)window.GetWindowHeight(), 0.1f, 100.0f)));

		//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::rotate(
			glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f)), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))));
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

		angle++;

		mike1.Draw();

		mike2.Draw();

		mike3.Draw();

		//glBindVertexArray(mike1.GetVAOId());
		//glBindTexture(GL_TEXTURE_2D, mike1.GetTextureId());

		//glDrawArrays(GL_TRIANGLES, 0, mike1.GetVertexCount());

		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		glUseProgram(0);

		glDisable(GL_DEPTH_TEST);
		
		window.Swap();
	}


	return 0;
}