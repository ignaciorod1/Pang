#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Esfera: public ObjetoMovil
{
protected:
	float radio;
	unsigned char rojo, verde, azul;
	friend class Interaccion;

public:

	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual Esfera* dividir();
	virtual ~Esfera();
	void SetRadio(float r);
	void SetColor(float r, float g, float b);
	void Dibuja();
	float GetRadio();
};

