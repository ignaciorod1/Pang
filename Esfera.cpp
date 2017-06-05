#include "Esfera.h"
#include "Pared.h"
#include "glut.h"

Esfera::Esfera()
{
	radio = 1.0f;
	aceleracion.y = -9.8f;
	velocidad.x = 4;
	velocidad.y = 4;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	rojo = verde = 255;
	azul = 0;
	aceleracion.y = -9.8;
}

Esfera* Esfera::dividir()
{
	if (radio<1.0f)
		return 0; //no dividimos
	radio /= 2.0f;//Dividimos el radio por 2
				  //Creamos una esfera nueva, copiando la actual
	Esfera *aux = new Esfera(*this);
	//Les damos nuevas velocidades
	aux->SetVel(5, 8);//a la nueva mitad
	SetVel(-5, 8);//a la mitad original
	return aux;
}

Esfera::~Esfera()	{}

void Esfera::SetRadio(float r) {radio = r;}

float Esfera::GetRadio() {return radio;}

void Esfera::SetColor(float r, float g, float b)
{
	rojo = r;
	verde = g;
	azul = b;
}

void Esfera::Dibuja()
{
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x, - posicion.y, 0);
	glPopMatrix();
}
