#pragma once
#include "Vector2D.h"
class Wall
{
	
	unsigned char rojo, azul, verde;
	Vector2D limit1, limit2;

public:

	Wall();
	virtual ~Wall();
	
	void SetPos(float x1, float x2, float y1, float y2);
	void SetColor(float r, float g, float b);
	float distancia(Vector2D punto, Vector2D *direccion = 0);
	void Dibuja();
	friend class Interaccion;
};

