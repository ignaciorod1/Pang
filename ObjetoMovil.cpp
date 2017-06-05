#include "ObjetoMovil.h"



ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::Mueve(float t) {

	posicion = posicion + velocidad*t + aceleracion*(0.5f*t*t);
	velocidad = velocidad + aceleracion*t;
}

void ObjetoMovil::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}


void ObjetoMovil::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}


Vector2D ObjetoMovil::GetPos()
{
	return posicion;
}