#include "Mundo.h"
#include <math.h>
#include "glut.h"

World::World()
{}

World::~World()
{
	esferas.destruirContenido();
	disparos.destruirContenido();
}

void World::Inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	bonus.SetPos(5.0f, 15.0f);
	plataforma.SetPos(-5.0, 9.0, 5.0, 9.0);
	
	Esfera *e1 = new Esfera(1, 2, 4, 5, 15);
	e1->SetColor(200, 0, 0);
	esferas.agregar(e1); //esfera

	Esfera *e2 = new Esfera(2, -2, 4, -5, 15);
	e2->SetColor(0, 0, 255);
	esferas.agregar(e2); //esfera2

	EsferaPulsante* esfera_pulsante = new EsferaPulsante;
	esfera_pulsante->SetColor(0, 255, 0);
	esferas.agregar(esfera_pulsante);
	

	for (int i = 1; i < 5; i++)
	{
		Esfera* aux = new Esfera(0.75 + i*0.25, i, 1 + i, i, i);
		esferas.agregar(aux);
	}

}

void World::Dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	box.Dibuja();
	dude.Dibuja();
	bonus.Dibuja();
	plataforma.Dibuja();
	esferas.Dibuja();
	disparos.dibuja();
	disparo_especial.Dibuja();
	
}

void World::Mueve() {

	float t = 0.025;

	dude.Mueve(t);
	disparos.mueve(t);
	esferas.Mueve(t);
	bonus.Mueve(t);
	disparo_especial.Mueve(t);
	disparos.colision(box);

	esferas.rebote();
	esferas.rebote(box);
	esferas.rebote(plataforma);

	Esfera *aux = esferas.colision(dude);

	Interaccion::rebote(dude, box);

	for (int i = 0; i<esferas.getNumero(); i++)
	{
		if (Interaccion::colision(disparo_especial, *esferas[i]))
		{
			Esfera* e = esferas[i]->dividir();
			if (e == 0) //no division
				esferas.eliminar(esferas[i]);
			else
				esferas.agregar(e);
			disparo_especial.SetPos(0, 0);
			disparo_especial.SetVel(0, 0);
			break;
		}
	}
	
}

void World::Tecla (unsigned char key )
{
	switch (key) 
	{	
		case ' ':
		{
			Shot *s = new Shot();
			Vector2D v = dude.GetPos();
			s->SetPos(v.x, v.y);
			disparos.agregar(s);
			break;
		}

		case 'z':
		{
			Vector2D v = dude.GetPos();
			disparo_especial.SetPos(v.x, v.y);
			disparo_especial.SetVel(0 , 20);
			break;
		}
		case '1':
			esferas.agregar(new Esfera(0.5f, 0, 10));
			break;
		case '2':
			esferas.agregar(new Esfera(1.0f, 0, 10));
			break;
		case '3':
			esferas.agregar(new Esfera(1.5f, 0, 10));
			break;
		case '4':
			esferas.agregar(new Esfera(2.0f, 0, 10));
			break;
	}
}

void World::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		dude.SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		dude.SetVel(5.0f, 0.0f);
		break;
	}
}