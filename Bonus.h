#pragma once
#include "Vector2D.h"
#include <stdlib.h>

class Bonus
{

	Vector2D aceleracion, velocidad, posicion;
	float lado;

public:

	void SetPos(float x, float y);
	void Dibuja();
	void Mueve (float);

	Bonus();
	virtual ~Bonus();
};

