#include "Hombre.h"
#include "glut.h"

Hombre::Hombre(){               // Constructor de Hombre
	azul=rojo=verde=255;		// default color is WHITE
	altura = 1.8f;
	posicion.x = 0;
	posicion.y = 0; 
}

Hombre::~Hombre() {}

void Hombre::SetAltura(float height)
{
	altura = height;
}

float Hombre::GetPos() {
	return posicion.x;
}

void Hombre::Dibuja(){

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

float Hombre::GetAltura() {
	return altura;
}