#include <glut.h>
#include <Math.h>
#include "Texture.h"
#include "Planets.h"
#include "Moons.h"
#include <stdlib.h>
#include <stdio.h>

#define checkImageWidth 500
#define checkImageHeight 500
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

float x = 0.0f, y = 200.0f, z = 1000.0f;
float lX = 0.0f, lY = 0.0f, lZ = 0.0f, lZ2 = 0.0f;

float RotX, RotY;
float camDistance = 70, camAngle = 0, camDist2 = 70, camAngle2 = 0;
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

Moons* Luna;
Moons* Deimos;
Moons* Phobos;
Moons* Ganymede;
Moons* Callisto;
Moons* Io;
Moons* Europa;
Moons* Titan;
Moons* Rhea;
Moons* Iapetus;
Moons* Dione;
Moons* Tethys;
Moons* Enceladus;
Moons* Mimas;


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

	//glTranslatef(x,y,z);
	gluPerspective(100.0, 1.66, 1.0, 2000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{	
	////////////////////////////////////////
	//                                    //
	//     Planet and Moon init calls     //
	//                                    //
	////////////////////////////////////////

	//Planets//
	Mercury = new Planets(0.383f, 1.61f, 58.0f, 0.8f, 0.5f, 0.5f);
	Venus = new Planets(0.949f, 1.18f, 108.0f, 1.0f, 0.0f, 0.0f);
	Earth = new Planets(1.0f, 1.0f, 150.0f, 0.0f, 0.0f, 1.0f);
	Mars = new Planets(0.532f, 0.81, 228.0f, 1.0f, 0.5f, 0.5f);
	Jupiter = new Planets(11.21f, 0.439f, 778.0f, 0.7f, 0.5f, 0.5f);
	Saturn = new Planets(9.45f, 0.325f, 1429.0f, 0.6f, 0.5f, 0.5f);
	Uranus = new Planets(4.01f, 0.229f, 2871.0f, 0.5f, 0.5f, 1.0f);
	Neptune = new Planets(3.88f, 0.182f, 4504.0f, 0.0f, 0.0f, 1.0f);
	Pluto = new Planets(0.187f, 0.158f, 5913.0f, 0.0f, 0.0f, 1.0f);
	
	//Earth Moon//
	Luna = new Moons(Earth, 0.27f, 0.15f, 4.0f, 3.0f, 3.0f, 3.0f, false);
	//Mars Moons//
	Deimos = new Moons(Mars, 0.07f, 0.15f, 4.0f, 3.0f, 3.0f, 3.0f, false);
	Phobos = new Moons(Mars, 0.07f, 0.10f, 3.5f, 3.0f, 3.0f, 3.0f, false);
	//Jupiter moons//
	Ganymede = new Moons(Jupiter, 0.45f, 0.15f, 20.0f, 6.0f, 3.0f, 3.0f, false);
	Callisto = new Moons(Jupiter, 0.42f, 0.13f, 28.0f, 3.0f, 3.0f, 3.0f, false);
	Io = new Moons      (Jupiter, 0.28f, 0.16f, 14.0f, 7.0f, 7.0f, 3.0f, false);
	Europa = new Moons  (Jupiter, 0.25f, 0.14f, 18.0f, 7.0f, 3.0f, 3.0f, false);
	//Saturn moons//
	Titan = new Moons(Saturn, 0.45f, 0.13f, 22.0f, 0.8f, 0.4f, 0.4f, true);
	Rhea = new Moons(Saturn, 0.13f, 0.12f, 14.0f, 0.6f, 0.5f, 0.5f, true);
	Iapetus = new Moons(Saturn, 0.13f, 0.15f, 38.0f, 0.7f, 0.6f, 0.6f, true);
	Dione = new Moons(Saturn, 0.10f, 0.14f, 18.0f, 0.6f, 0.3f, 0.3f, true);
	Tethys = new Moons(Saturn, 0.09f, 0.17f, 16.0f, 0.6f, 0.4f, 0.4f, true);
	Enceladus = new Moons(Saturn, 0.09f, 0.16f, 20.0f, 0.8f, 0.4f, 0.4f, true);
	Mimas = new Moons(Saturn, 0.09f, 0.11f, 17.0f, 7.0f, 0.4f, 0.4f, true);
}

void display()
{
	
	glEnable(GL_DEPTH_TEST);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//glTranslatef(x, y, z);
	
	gluLookAt(x, y, z, lX + x, lY+y, lZ + z, 0, 1, 0);

	
	lX = sin(camAngle) * camDistance;
	lZ = -cos(camAngle)* camDistance;
	lY = sin(camAngle2)* camDistance;

	////////////////////////////////////////
	//                                    //
	//     Planet and Moon draw calls     //
	//                                    //
	////////////////////////////////////////

	//Planets//
	Mercury->Draw();
	Venus->Draw();
	Earth->Draw();
	Mars->Draw();
	Jupiter->Draw();
	Saturn->Draw();
	Uranus->Draw();
	Neptune->Draw();
	Pluto->Draw();


	//Earth moon//
	Luna->Draw();
	//Mars Moons//
	Deimos->Draw();
	Phobos->Draw();
	//Jupiter Moons//
	Ganymede->Draw();
	Callisto->Draw();
	Io->Draw();
	Europa->Draw();
	//Saturn Moons//
	Titan->Draw();
	Rhea->Draw();
	Iapetus->Draw();
	Dione->Draw();
	Tethys->Draw();
	Enceladus->Draw();
	Mimas->Draw();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glutSolidSphere(109.1 * 20, 360, 20);
	glPopMatrix();


	

	glutSwapBuffers();
}

int nx, ny;

void mouseMotion(int xx, int yy)
{
	if(nx > xx)
		camAngle += (nx - xx)/50.5f;
	else if(xx > nx) 
		camAngle -= (xx - nx)/50.5f;
	nx = xx;
	if(ny > yy)
		camAngle2 += (ny - yy)/50.5f;
	else if(yy > ny)
		camAngle2 += (ny - yy)/50.5f;
	ny = yy;
	glutPostRedisplay();
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
		z = lZ + z;
		x = lX + x;
		y = lY + y;
		break;
	case 's':
		z -= 5.0f;
		break;
	}
	glutPostRedisplay();
}

void HandleTimer(int ID)
{
	glutTimerFunc(33,HandleTimer,1);
	

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

	glutPassiveMotionFunc(mouseMotion);

	glutKeyboardFunc(keyboard);

	glutTimerFunc(1000, HandleTimer, 1);

	glutMainLoop();
	
	return 0;
}