#include <stdio.h>
#include <stdlib.h>
#include <GL/glfw.h>

static unsigned width = 640, height = 480;
static int keep_going = 1;
static float clear_r = 0.2, clear_g = 0.2, clear_b = 0.9;

void clamp(float *f)
{
	if (*f < 0.0)
		*f = 0.0;
	if (*f > 1.0)
		*f = 1.0;
}

void refresh_clear_color(void)
{
	clamp(&clear_r);
	clamp(&clear_g);
	clamp(&clear_b);
	glClearColor(clear_r, clear_g, clear_b, 0.0);
}

void GLFWCALL key_input(int key, int action)
{
	if (key == GLFW_KEY_ESC) {
		keep_going = 0;
		printf("action=%d\n", action);
	}
}

void GLFWCALL mouse_move(int x, int y)
{
	/* printf("move=%d,%d\n", x, y); */
	clear_r = (float)x / width;
	clear_g = (float)y / height;
	refresh_clear_color();

}

void GLFWCALL mouse_wheel(int pos)
{
	/* printf("wheel=%d\n", pos); */
	if (pos < -10)
		glfwSetMouseWheel(pos = -10);
	if (pos > 10)
		glfwSetMouseWheel(pos = 10);
	clear_b = abs(pos) / 10.0;
	refresh_clear_color();
}

int GLFWCALL win_close(void)
{
	keep_going = 0;
	return GL_TRUE; /* please continue with closing the window */
}

int main()
{
	if (!glfwInit())
		return 1;

	if (!glfwOpenWindow(width, height, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
		return 1;

	glfwSetWindowTitle("Client_glfw");

	glfwSetKeyCallback(key_input);
	glfwSetWindowCloseCallback(win_close);
	glfwSetMousePosCallback(mouse_move);
	glfwSetMouseWheelCallback(mouse_wheel);

	refresh_clear_color();

	while (keep_going) {
		if (!glfwGetWindowParam(GLFW_OPENED)) { /* is window closed? */
			keep_going = 0;
			break;
		}

		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSleep(0.100);

		glfwSwapBuffers();
	}

	return 0;
}
