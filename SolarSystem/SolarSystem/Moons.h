#pragma once
#include "Planets.h"
class Moons
{
public:
	Moons(void);
	Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring);
	~Moons(void);
	float x, z;
	void Draw();
private:
	Planets* planet;
	float angle, distance, radius, rotSpeed;
	float R,G,B;
	bool ring;
};

