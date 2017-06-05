#include "Disparo.h"
#include "glut.h"


float Shot::GetCalibre() {
	return calibre;
}

void Shot::Dibuja(){
	glPushMatrix();
	glLineWidth(2.5);					// DIBUJO DE LA LINEA
	glColor3f(0, 255, 0.0);
	glBegin(GL_LINES);
	glVertex3f(posicion.x, 0.0, 0.0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();

	glLineWidth(5);					// DIBUJO DE LA ESTELA
	glColor3f(255, 255, 255);
	glBegin(GL_LINES);
	glVertex3f(posicion.x, 0.0, 0.0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();

	glColor3f(0, 120, 0);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(calibre,1, 50, 50);
	
	glPopMatrix();
}

Shot::Shot()
{
	aceleracion.y = 0;
	velocidad.y = 10;
	posicion.x = posicion.y = 0;
	calibre = 0.25f;
}

Shot::Shot(Vector2D pos)
{
	posicion.x = pos.x;
	posicion.y = pos.y;
	velocidad.y = 10;
	calibre = 0.25f;
}


Shot::~Shot()
{
}
