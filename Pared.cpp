		#include "Pared.h"
#include "glut.h"

Wall::Wall()	{rojo = verde = azul = 255;}


Wall::~Wall(){}


void Wall::SetColor(float r, float g, float b) {
	rojo = r;
	verde = g;
	azul = b;
}

void Wall::SetPos(float x1, float y1, float x2, float y2) {
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
}

void Wall::Dibuja(){

	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);

	glBegin(GL_POLYGON);
	glVertex3d(limit2.x, limit2.y, 10);
	glVertex3d(limit1.x, limit1.y, 10);
	glColor3ub(10,10,255);
	glVertex3d(limit1.x, limit1.y, -10);
	glVertex3d(limit2.x, limit2.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}


float Wall::distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - limit1);
	Vector2D v = (limit2 - limit1).unitario();
	float longitud = (limit1 - limit2).modulo();
	Vector2D dir;
	float valor = u*v;
	float distancia = 0;
	if (valor<0)
		dir = u;
	else if (valor>longitud)
		dir = (punto - limit2);
	else
		dir = u - v*valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}