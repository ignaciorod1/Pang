#include "DisparoEspecial.h"



DisparoEspecial::DisparoEspecial()
{
	velocidad.y = 0;
	posicion.x = posicion.y = 0;
	calibre = 0.35f;
}


DisparoEspecial::~DisparoEspecial()
{
}


void DisparoEspecial::Dibuja()
{
	glPushMatrix();
	glLineWidth(2.5);					// DIBUJO DE LA LINEA
	glColor3f(rand() % 255, 0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(posicion.x, 0.0, 0.0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();

	glLineWidth(5);					// DIBUJO DE LA ESTELA
	glColor3f(0, 255, 255);
	glBegin(GL_LINES);
	glVertex3f(posicion.x, 0.0, 0.0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();

	glColor3f(rand() % 50, rand() % 50, 0);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidSphere(0.3, 20, 20);

	glPopMatrix();
}