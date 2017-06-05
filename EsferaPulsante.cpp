#include "EsferaPulsante.h"



EsferaPulsante::EsferaPulsante()
{
	pulso = 0.5;
	radio_max = 2;
	radio_min = 0.5;
	aceleracion.x = 0;
	aceleracion.y = 0;
	posicion.x = 0;
	posicion.y = 5;
}


EsferaPulsante::~EsferaPulsante()
{
}

void EsferaPulsante::Mueve(float t)
{
	posicion = posicion + velocidad*t + aceleracion*(0.5f*t*t);
	velocidad = velocidad + aceleracion*t;
	if (radio>radio_max)
		pulso = -pulso;
	if (radio<radio_min)
		pulso = -pulso;
	radio += pulso*t;
	rojo = radio * 255;
	verde = 255 - radio * 100;
	azul = 100 + radio * 50;
}
