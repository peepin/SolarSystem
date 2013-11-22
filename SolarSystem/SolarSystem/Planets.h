#pragma once

#include <glut.h>
#include <Math.h>

class Planets
{
private:
	float x, z, angle, distance, radius, rotSpeed;
	float R,G,B;
public:
	Planets(void);

	Planets(float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB);
	void Draw();

	~Planets(void);
};

