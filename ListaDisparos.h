#pragma once
#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"
#include "Interaccion.h"
class ListaDisparos
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();			

	bool agregar(Shot* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	float GetNumero();
	void colision(Wall p);
	void colision(Caja c);
private:
	Shot * lista[MAX_DISPAROS];
	int numero;
};

