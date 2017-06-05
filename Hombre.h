#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Hombre: public ObjetoMovil
{

	unsigned char rojo, verde, azul;
	float altura;

	friend class Interaccion;

public:

	Hombre();
	virtual ~Hombre();

	void SetAltura(float altura);
	float GetAltura();
	float GetPos();
	void Dibuja();

};

