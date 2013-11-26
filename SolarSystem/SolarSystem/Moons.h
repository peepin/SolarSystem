#pragma once
#include "Planets.h"
//#include <iostream>

class Moons
{
public:
	Moons(void);
	Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring, std::string sMoonObj);
	Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring);
	void drawmodel(void);
	
	~Moons(void);
	float x, z;
	void Draw();
private:
	GLMmodel* model1;
	std::string cMoonObj;
	Planets* planet;
	float angle, distance, radius, rotSpeed;
	float R,G,B;
	bool ring;
};

