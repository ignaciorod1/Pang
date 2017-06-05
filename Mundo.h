#pragma once
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Bonus.h"
#include "Caja.h"
#include "Interaccion.h"
#include "ListaDeEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
class World
{
protected:
	DisparoEspecial disparo_especial;
	float x_ojo, y_ojo, z_ojo;
	Caja box;
	Bonus bonus;
	Hombre dude;
	Wall plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;

public:

	World();
	~World();

	void Mueve();
	void Dibuja();
	void Tecla(unsigned char key);
	void Inicializa();
	void TeclaEspecial(unsigned char);
};

