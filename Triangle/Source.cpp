#include <iostream>
#include <glut.h>

void render(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("OpenGL Triangle");
	glutDisplayFunc(render);

	glutMainLoop();
	
	return 1;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.5f, 0.5f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -0.5f);
	glEnd();

	glutSwapBuffers();
	glutKeyboardFunc(keyboard);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);
	}

	if (key == 'f')
	{
		glutFullScreen();
	}
}