#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i<MAX_DISPAROS; i++)
		lista[i] = 0;
}


ListaDisparos::~ListaDisparos()
{
}

float ListaDisparos::GetNumero()
{
	return numero;
}
void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

bool ListaDisparos::agregar(Shot *s) 
{
	if (numero < MAX_DISPAROS)
		lista[numero++] = s;
	else
		return false;
	return true;
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaDisparos::colision(Wall p)
{
	for (int i = 0; i < numero; i++)
		if (Interaccion::colision(*lista[i], p))
			lista[i]->SetVel(0, 0);
}

void ListaDisparos::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
		if (Interaccion::colision(*lista[i], c))
		{
			lista[i]->SetVel(0, 0);
		}
}


