#include "Moons.h"


Moons::Moons(void)
{
}

Moons::Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring){
	radius = sradius * 20;
	rotSpeed = srotSpeed * 20;
	distance = sdistance * 20;
	R = sR; G = sG; B = sB;
	angle = 0;
	planet = splanet;
	ring = sring;
}

Moons::~Moons(void)
{
}

void Moons::Draw(){

	glPushMatrix();
	glTranslatef(x, 0, z);
	glColor3f(R, G, B);
	glutSolidSphere(radius, 360, 20);
	glPopMatrix();

	z = cos(angle) * distance + planet->z;
	x = sin(angle) * distance + planet->x;

	if(angle >= 360) angle = 0.0f;
	else angle += rotSpeed * 0.01;
	if(ring){
		glLineWidth(1);
		glBegin(GL_LINES);
	
		for (int i = 0; i < 360; i++)
		{
			//float degInRad = i * 1;
			float degInRad = 2 * 3.14 * i / 360;
			glVertex3f(cos(degInRad)* distance + planet->x, 0, sin(degInRad) * distance+ planet->z);
		}
	}
 
	glEnd();


}