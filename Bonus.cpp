#include "Bonus.h"
#include "glut.h"



void Bonus::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Bonus::Dibuja(){
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30,1,1,1);
	glColor3f (rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX); 
	glutSolidCube(lado);
	glPopMatrix();
}

void Bonus::Mueve(float t){
	posicion = posicion + velocidad*t + aceleracion*(0.5f*t*t);
	velocidad = velocidad + aceleracion*t;
}


Bonus::Bonus()
{
	lado= 0.5;
	posicion.x = 0.0;
	posicion.y = 9;
	velocidad.y = 0.07;
	aceleracion.y = -9.81;
}


Bonus::~Bonus()
{
}
