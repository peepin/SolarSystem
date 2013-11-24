#pragma once

#include <glut.h>
#include <Math.h>

class Planets
{
private:
	float angle, distance, rotSpeed;
	float R,G,B;
public:
	Planets(void);
	float x, z,radius;
	Planets(float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB);
	void Draw();

	~Planets(void);
};

