#include "ListaDeEsferas.h"


ListaEsferas::ListaEsferas() // inicializa el vector a 0
{
	numero = 0;
	for (int i = 0; i<MAX_ESFERAS; i++)
		lista[i] = 0;
}

ListaEsferas::~ListaEsferas()	{}

bool ListaEsferas::agregar(Esfera *e)
{
	if (numero<MAX_ESFERAS)
		lista[numero++] = e;
	else
		return false;
	return true;
}	

void ListaEsferas::Dibuja()
{
	for (int i = 0; i<numero; i++)
		lista[i]->Dibuja();
}

void ListaEsferas::Mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaEsferas::rebote(Caja caja)
{	
	for (int i = 0; i<numero; i++)
		Interaccion::rebote(*lista[i], caja);
}

void ListaEsferas::rebote(Wall p)
{
	for (int i = 0; i<numero; i++)
		Interaccion::rebote(*lista[i] , p);
}

void ListaEsferas::rebote() 
{
	for (int i = 0; i < numero; i++)
	{
		for (int j = 1; j<numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
	}
}

void ListaEsferas::eliminar(int index)
{
	if ((index<0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i<numero; i++)
		lista[i] = lista[i + 1];
}
void ListaEsferas::eliminar(Esfera *e)
{
	for (int i = 0; i<numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Esfera* ListaEsferas::colision(Hombre hombre)
{
	for (int i = 0; i<numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), hombre))
			return lista[i];
	}
	return 0; //no hay colisión
}

Esfera* ListaEsferas::colision(DisparoEspecial d)
{
	for (int i = 0; i<numero; i++)
	{
		if (Interaccion::colision(d, *(lista[i])))
			return lista[i];
	}
	return 0; //no hay colisión
}

Esfera *ListaEsferas::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i<0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}


void ListaEsferas::destruirContenido()
{
	for (int i = 0; i<numero; i++)
		delete lista[i];
	numero = 0;
}