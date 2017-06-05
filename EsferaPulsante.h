#pragma once
#include "Esfera.h"
class EsferaPulsante :
	public Esfera
{
	float pulso;
	float radio_max;
	float radio_min;
public:
	EsferaPulsante(void);
	~EsferaPulsante(void);
	void Mueve(float t);
};

