#pragma once
#include "Pared.h"


class Caja
{
	Wall suelo, techo, pared_izq, pared_der;
	unsigned char rojo, verde, azul;

public:

	Caja();
	virtual ~Caja();

	void Dibuja();
	friend class Interaccion;
};

