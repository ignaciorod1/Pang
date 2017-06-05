#pragma once
#include "Esfera.h"
#include "Interaccion.h"

#define MAX_ESFERAS 100

class ListaEsferas
{
	Esfera *lista[MAX_ESFERAS];
	int numero;

public:

	ListaEsferas();
	~ListaEsferas();

	bool agregar(Esfera *e);
	void Dibuja();
	void rebote();
	void rebote(Wall);
	void rebote(Caja);
	void Mueve(float);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera *e);
	Esfera* colision(Hombre);
	Esfera* colision(DisparoEspecial);
	Esfera * operator [](int i);
	int getNumero() { return numero; }


};

