#include "Moons.h"


Moons::Moons(void)
{
}

Moons::Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring, std::string sMoonObj)
{
	radius = sradius * 20;
	rotSpeed = srotSpeed * 20;
	distance = sdistance * 20;
	R = sR; G = sG; B = sB;
	angle = 0;
	planet = splanet;
	ring = sring;

	model1 = NULL;
	cMoonObj = sMoonObj;
}

Moons::Moons(Planets* splanet, float sradius, float srotSpeed, float sdistance, float sR, float sG, float sB, bool sring)
{
	radius = sradius * 20;
	rotSpeed = srotSpeed * 20;
	distance = sdistance * 20;
	R = sR; G = sG; B = sB;
	angle = 0;
	planet = splanet;
	ring = sring;

	model1 = NULL;
	cMoonObj = "";
}

Moons::~Moons(void)
{
}

void Moons::drawmodel(void)
{
	// Load the model only if it hasn't been loaded before
	// If it's been loaded then pmodel1 should be a pointer to the model geometry data...otherwise it's null
    if (!model1) 
	{
		// this is the call that actualy reads the OBJ and creates the model object
		
		model1 = glmReadOBJ(strdup(cMoonObj.c_str()));	
        if (!model1) exit(0);
		// This will rescale the object to fit into the unity matrix
		// Depending on your project you might want to keep the original size and positions you had in 3DS Max or GMAX so you may have to comment this.
        
		//glmUnitize(model1);
		// These 2 functions calculate triangle and vertex normals from the geometry data.
		// To be honest I had some problem with very complex models that didn't look to good because of how vertex normals were calculated
		// So if you can export these directly from you modeling tool do it and comment these line
		// 3DS Max can calculate these for you and GLM is perfectly capable of loading them
        glmFacetNormals(model1);        
		glmVertexNormals(model1, 90.0);
    }
    // This is the call that will actualy draw the model
	// Don't forget to tell it if you want textures or not :))
    glmDraw(model1, GLM_SMOOTH | GLM_TEXTURE);
	
}

void Moons::Draw(){

	glPushMatrix();
	glTranslatef(x, 0, z);
	//glColor3f(R, G, B);

	if(cMoonObj.length() !=0) drawmodel();

	if(cMoonObj.length() == 0) glutSolidSphere(radius, 360, 20);
	
	
	glPopMatrix();

	z = cos(angle) * distance + planet->z;
	x = sin(angle) * distance + planet->x;

	if(angle >= 360) angle = 0.0f;
	else angle += rotSpeed * 0.01;
	if(ring){
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
	
		for (int i = 0; i < 360; i++)
		{
			//float degInRad = i * 1;
			float degInRad = 2 * 3.14 * i / 360;
			glVertex3f(cos(degInRad)* distance + planet->x, 0, sin(degInRad) * distance+ planet->z);
		}
	}
 
	glEnd();
}