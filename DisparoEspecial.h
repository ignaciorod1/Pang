#pragma once
#include <iostream>
#include <time.h>
#include "Disparo.h"
#include "glut.h"

class DisparoEspecial :
	public Shot
{
public:

	DisparoEspecial();
	~DisparoEspecial();

	void Dibuja();
};

