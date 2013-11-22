#include <glut.h>
#include <Math.h>
#include "Texture.h"
#include "Planets.h"

#include <stdlib.h>
#include <stdio.h>

#define checkImageWidth 500
#define checkImageHeight 500
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

float x = 2.5f, y = 0.0;

Texture treeTexture;

Planets* Mercury;
Planets* Venus;
Planets* Earth;
Planets* Mars;
Planets* Jupiter;
Planets* Saturn;
Planets* Uranus;
Planets* Neptune;
Planets* Pluto;


void makeCheckImage(void)
{
   int i, j, c;
    
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}

void reshape (int width, int height) 
{   
	glViewport (0, 0, (GLsizei) width, (GLsizei) height); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	gluPerspective(100.0, 1.66, 1.0, 20000);
	gluLookAt(0, 800, -1000, 0, 0, 0, 0, 1, 0);
}

void init()
{	
	Mercury = new Planets(0.383f, 1.61f, 58.0f, 0.8f, 0.5f, 0.5f);
	Venus = new Planets(0.949f, 1.18f, 108.0f, 1.0f, 0.0f, 0.0f);
	Earth = new Planets(1.0f, 1.0f, 150.0f, 0.0f, 0.0f, 1.0f);
	Mars = new Planets(0.532f, 0.81, 228.0f, 1.0f, 0.5f, 0.5f);
	Jupiter = new Planets(11.21f, 0.439f, 778.0f, 0.7f, 0.5f, 0.5f);
	Saturn = new Planets(9.45f, 0.325f, 1429.0f, 0.6f, 0.5f, 0.5f);
	Uranus = new Planets(4.01f, 0.229f, 2871.0f, 0.5f, 0.5f, 1.0f);
	Neptune = new Planets(3.88f, 0.182f, 4504.0f, 0.0f, 0.0f, 1.0f);
	Pluto = new Planets(0.187f, 0.158f, 5913.0f, 0.0f, 0.0f, 1.0f);
}

void display()
{
	glEnable(GL_DEPTH_TEST);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Mercury->Draw();
	Venus->Draw();
	Earth->Draw();
	Mars->Draw();
	Jupiter->Draw();
	Saturn->Draw();
	Uranus->Draw();
	Neptune->Draw();
	Pluto->Draw();


	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glutSolidSphere(109.1f, 360, 20);
	glPopMatrix();


	glutSwapBuffers();
}

void keyboard(unsigned char key, int xx, int yy)
{
	switch(key)
	{
	case 'a':
		//x--;
		break;
	case 'd':
		//x++;
		break;
	case 'w':
		//y++;
		break;
	case 's':
		//y--;
		break;
	}
	glutPostRedisplay();
}

void HandleTimer(int ID)
{
	glutTimerFunc(33,HandleTimer,1);
	
	/*earthZ = cos(earthAngle) * earthDistance;
	earthX = sin(earthAngle) * earthDistance;

	earthAngle += 0.01;*/


	glutPostRedisplay();	
}

int main(int argc, char* argv[])
{
	//LoadTGA(&treeTexture, "ColorfulMustache.tga");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("Solar System :: By: Alexei Haustov, Kyle Bannister");
	init();
	

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, HandleTimer, 1);

	glutMainLoop();
	
	return 0;
}