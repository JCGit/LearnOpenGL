#include<stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

void key_callback(GLFWwindow *win, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
	else
		printf("key:%d\n", key);
}

int main() 
{
	// glfw 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *win = glfwCreateWindow(800, 600, "J.C.LearnOpenGL", NULL, NULL);
	glfwMakeContextCurrent(win);
	if (win == NULL)
	{
		//std::cout  << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(win, key_callback);

	// glew
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		return -1;

	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(win))
	{
		glfwPollEvents();


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(win);
	}

	glfwTerminate();
}
