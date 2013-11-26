#pragma once
#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <glut.h>
#include <Math.h>
#include "glm.h"
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
	void drawmodel(void);
	GLMmodel* model1;
	~Planets(void);
};

