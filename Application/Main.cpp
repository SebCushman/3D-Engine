#include "pch.h"
#include "Engine/Engine.h"
#include "Engine/Graphics/VertexArray.h"
#include "Engine/Graphics/VertexIndexArray.h"

int main(int argc, char** argv)
{
	nc::Engine engine;
	engine.Startup();

	//static float vertices[] = {
	//	// front
	//	-1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
	//	 1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
	//	 1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
	//	-1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
	//	// back
	//	-1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
	//	 1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
	//	 1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	//	-1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
	//};

	static float vertices[] =
	{
		-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,



		-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,



		-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,



		 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,



		-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		-1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,



		-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f
	};

	//unsigned short = 16bits
	//static GLushort indices[] =
	//{
	//	// front
	//	0, 1, 2,
	//	2, 3, 0,
	//	// right
	//	1, 5, 6,
	//	6, 2, 1,
	//	// back
	//	7, 6, 5,
	//	5, 4, 7,
	//	// left
	//	4, 0, 3,
	//	3, 7, 4,
	//	// bottom
	//	4, 5, 1,
	//	1, 0, 4,
	//	// top
	//	3, 2, 6,
	//	6, 7, 3
	//};


	nc::Program program;
	program.CreateShaderFromFile("Shaders\\phong.vert", GL_VERTEX_SHADER);
	program.CreateShaderFromFile("Shaders\\phong.frag", GL_FRAGMENT_SHADER);
	program.Link();
	program.Use();

	/*nc::VertexIndexArray vertexIndexArray;
	vertexIndexArray.Create("vertex");
	vertexIndexArray.CreateBuffer(sizeof(vertices), sizeof(vertices) / (sizeof(float) * 5), vertices);
	vertexIndexArray.SetAttribute(0, 3, 5 * sizeof(float), 0);
	vertexIndexArray.SetAttribute(1, 2, 5 * sizeof(float), 3 * sizeof(float));
	vertexIndexArray.CreateIndexBuffer(GL_UNSIGNED_SHORT, sizeof(indices) / sizeof(GLushort), indices);*/

	/*nc::VertexArray vertexArray;
	vertexArray.Create("vertex");
	vertexArray.CreateBuffer(sizeof(vertices), sizeof(vertices) / (sizeof(float) * 6), vertices);
	vertexArray.SetAttribute(0, 3, 6 * sizeof(float), 0);
	vertexArray.SetAttribute(1, 3, 6 * sizeof(float), 3 * sizeof(float));*/

	nc::VertexArray vertexArray;
	vertexArray.Create("vertex");

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texcoords;
	nc::Model::Load("models/ogre.obj", positions, normals, texcoords);

	if (!positions.empty())
	{
		vertexArray.CreateBuffer(positions.size() * sizeof(glm::vec3), static_cast<GLsizei>(positions.size()), positions.data());
		vertexArray.SetAttribute(0, 3, 0, 0);
	}

	if (!normals.empty())
	{
		// complete code
		vertexArray.CreateBuffer(normals.size() * sizeof(glm::vec3), static_cast<GLsizei>(normals.size()), normals.data());
		vertexArray.SetAttribute(1, 3, 0, 0);
	}

	if (!texcoords.empty())
	{
		// complete code
		vertexArray.CreateBuffer(texcoords.size() * sizeof(glm::vec2), static_cast<GLsizei>(texcoords.size()), texcoords.data());
		vertexArray.SetAttribute(2, 2, 0, 0);
	}


	//uniform
	glm::mat4 model = glm::mat4(1.0f);

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800/600.0f, 0.01f, 1000.0f);

	glm::vec3 eye{0, 0, 5};
	glm::mat4 view = glm::lookAt(eye, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	
	nc::Texture texture;
	texture.CreateTexture("Textures\\llama.jpg");

	program.SetUniform("material.ambient", glm::vec3{1, 1, 1});
	program.SetUniform("material.diffuse", glm::vec3{1, 1, 1});
	program.SetUniform("material.specular", glm::vec3{1, 1, 1});
	program.SetUniform("material.shininess", 32.0f);

	program.SetUniform("light.ambient", glm::vec3{ 0.05f, 0.35f, 0.45f });
	program.SetUniform("light.diffuse", glm::vec3{ 0, 0.7f, 1 });
	program.SetUniform("light.specular", glm::vec3{ 1, 1, 1 });
	glm::vec4 light{5, 2, 5, 1};

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_PumpEvents();
		engine.Update();

		float angle = 0;
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_E) == nc::InputSystem::eButtonState::HELD) {
			angle = 2.0f;
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_Q) == nc::InputSystem::eButtonState::HELD) {
			angle = -2.0f;
		}
		model = glm::rotate(model, angle * engine.GetTimer().DeltaTime(), glm::vec3(0, 1, 0));

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD) {
			eye.x -= 4 * engine.GetTimer().DeltaTime();
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD) {
			eye.x += 4 * engine.GetTimer().DeltaTime();
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == nc::InputSystem::eButtonState::HELD) {
			eye.z -= 4 * engine.GetTimer().DeltaTime();
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_S) == nc::InputSystem::eButtonState::HELD) {
			eye.z += 4 * engine.GetTimer().DeltaTime();
		}
		view = glm::lookAt(eye, eye + glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));

		glm::mat4 mvp = projection * view * model;
		//How to get it with the OpenGL code
		program.SetUniform("mvp", mvp);

		glm::mat4 model_view = view * model;
		program.SetUniform("model_view", model_view);

		glm::vec4 position = view * light;
		program.SetUniform("light.position", position);

		engine.GetSystem<nc::Renderer>()->BeginFrame();

		vertexArray.Draw();
		
		/*GLsizei numElements = sizeof(indices) / sizeof(GLushort);
		glDrawElements(GL_TRIANGLES, numElements, GL_UNSIGNED_SHORT, 0);*/

		engine.GetSystem<nc::Renderer>()->EndFrame();
	}
	engine.Shutdown();

	return 0;
}
