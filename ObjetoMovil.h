#pragma once
#include "Vector2D.h"
class ObjetoMovil
{

public:
	ObjetoMovil(void);
	~ObjetoMovil(void);
	virtual void Mueve(float t);
	void SetPos(float ix, float iy);
	void SetVel(float vx, float vy);
	Vector2D GetPos();
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};

