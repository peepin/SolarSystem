#include "Planets.h"


Planets::Planets(void)
{
}

Planets::Planets(float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB)
{
	radius = sradius * 20;
	rotSpeed = srotSpeed - srotSpeed;
	distance = sdistance * 20 + 109 * 20;
	R = sR;
	G = sG;
	B = sB;

	angle = 0;
}

void Planets::Draw()
{
	glPushMatrix();
	glTranslatef(x, 0, z);
	glColor3f(R, G, B);
	glutSolidSphere(radius, 360, 20);
	glPopMatrix();

	z = cos(angle) * distance;
	x = sin(angle) * distance;

	if(angle >= 360) angle = 0.0f;
	else angle += rotSpeed * 0.01;
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++)
	{
		//float degInRad = i * 1;
		float degInRad = 2 * 3.14 * i / 360;
		glVertex3f(cos(degInRad)* distance, 0, sin(degInRad) * distance);
	}
 
	glEnd();


	/* glBegin(GL_LINE_LOOP);
 
	 for (int i = 0; i < 360; i++)
	 {
		float degInRad = i * angle;
		glVertex2f(cos(degInRad)* distance, sin(degInRad) * distance);
	 }
 
	 glEnd();*/
}

Planets::~Planets(void)
{
}
