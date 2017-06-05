#include "Caja.h"


void Caja::Dibuja(){

	suelo.Dibuja();
	techo.Dibuja();
	pared_der.Dibuja();
	pared_izq.Dibuja();
}


Caja::Caja()
{
	suelo.SetColor(255,255, 255) ;
	techo.SetColor(255, 255, 255);
	pared_der.SetColor(255, 255, 255);
	pared_izq.SetColor(255, 255, 255);

	pared_der.SetPos(10.0, 0.0, 10.0, 20.0);		// RIGHT WALL
	pared_izq.SetPos(-10.0, 0.0, -10.0, 20.0);		// LEFT WALL
	suelo.SetPos(-10.0, 0.0, 10.0, 0.0);			// FLOOR
	techo.SetPos(-10.0, 20.0, 10.0, 20.0);			// CEILING	
}

Caja::~Caja()
{
}
