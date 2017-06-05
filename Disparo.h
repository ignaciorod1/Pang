#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Shot : public ObjetoMovil
{
protected:

	float calibre;

public:
	Shot();
	Shot(Vector2D);
	virtual ~Shot();

	void Dibuja();
	float GetCalibre();
};

