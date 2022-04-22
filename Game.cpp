#include "Game.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

Game::Game()
{
	model = Model("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	quit = false;
	angle = 0;
}

Game::~Game()
{
}

void Game::Run()
{
	//renderer.bind();

	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glUseProgram(shader.GetProgramId());

	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(
		glm::radians(45.0f), (float)window.GetWindowHeight() / (float)window.GetWindowHeight(), 0.1f, 100.0f)));

	//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::rotate(
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))));
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

	angle += 0.1f;

	glBindVertexArray(model.GetVAOId());
	glBindTexture(GL_TEXTURE_2D, model.GetTextureId());

	glDrawArrays(GL_TRIANGLES, 0, model.GetVertexCount());

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glUseProgram(0);

	glDisable(GL_DEPTH_TEST);

	/*renderer.unbind();

	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glUseProgram(shader.GetProgramId());

	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(
		glm::radians(45.0f), (float)window.GetWindowHeight() / (float)window.GetWindowHeight(), 0.1f, 100.0f)));

	//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::rotate(
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))));
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

	//angle++;

	glBindVertexArray(model.GetVAOId());
	glBindTexture(GL_TEXTURE_2D, renderer.GetTexture());

	glDrawArrays(GL_TRIANGLES, 0, model.GetVertexCount());

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glUseProgram(0);

	glDisable(GL_DEPTH_TEST);*/

	window.Swap();
}

void Game::Begin()
{
}

void Game::Tick()
{
}

void Game::BindRenderer()
{
	renderer.bind();
}

void Game::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::UseProgram()
{
	glEnable(GL_DEPTH_TEST);
	glUseProgram(shader.GetProgramId());
}

void Game::Uniform()
{
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(
		glm::radians(45.0f), (float)window.GetWindowHeight() / (float)window.GetWindowWidth(), 0.1f, 100.0f)));

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(glm::rotate(
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f)), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))));
}

void Game::IncreaseAngle()
{
	angle += 0.1f;
}

void Game::Draw()
{
	glBindVertexArray(model.GetVAOId());
	glBindTexture(GL_TEXTURE_2D, model.GetTextureId());

	glDrawArrays(GL_TRIANGLES, 0, model.GetVertexCount());

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glUseProgram(0);

	glDisable(GL_DEPTH_TEST);
}
