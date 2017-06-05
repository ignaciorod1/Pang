#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "DisparoEspecial.h"
#include "Esfera.h"
#include "Disparo.h"
#include <cmath>


class Interaccion
{
public:

	static void rebote(Hombre&, Caja);
	static void rebote(Esfera&, Caja);
	static bool rebote(Esfera&, Wall p);
	static bool rebote(Esfera&, Esfera&);

	static bool colision(Esfera, Hombre);
	static bool colision(Shot, Wall);
	static bool colision(Shot, Caja);
	static bool colision(Shot, Esfera);
	static bool colision(DisparoEspecial, Esfera);

	Interaccion();
	~Interaccion();
};

