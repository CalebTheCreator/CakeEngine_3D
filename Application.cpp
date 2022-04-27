#include "Application.h"

Application::Application()
{
	shader = Shader(ShaderType::Specular);
	model = Model("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	angle = 0;
}

Application::~Application()
{
	
}

void Application::Run()
{
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
		shader.Clear(projectionLoc, modelLoc, window, angle);
		model.Draw();
		shader.Draw();
		window.Swap();
	}
}
