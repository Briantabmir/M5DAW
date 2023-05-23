#include "Personaje.h"

// Constructor
Personaje::Personaje(string pNombrePersonaje, int pVida, int pAtaque, int pPosicionX, int pPosicionY)
{

	nombrePersonaje = pNombrePersonaje;
	vida = pVida;
	ataque = pAtaque;
	posicionX = pPosicionX;
	posicionY = pPosicionY;

}


// Setters
void Personaje::setNombrePersonaje(string pNombrePersonaje)
{
	nombrePersonaje = pNombrePersonaje;
}

void Personaje::setVida(int pVida)
{
	vida = pVida;
}

void Personaje::setAtaque(int pAtaque)
{
	ataque = pAtaque;
}

void Personaje::setPosicionX(int pPosicionX)
{
	posicionX = pPosicionX;
}

void Personaje::setPosicionY(int pPosicionY)
{
	posicionY = pPosicionY;
}

void Personaje::setPosicionInicialX(int pPosicionInicialX)
{
	posicionInicialX = pPosicionInicialX;
}

void Personaje::setPosicionInicialY(int pPosicionInicialY)
{
	posicionInicialY = pPosicionInicialY;
}

// Getters
string Personaje::getNombrePersonsaje()
{
	return nombrePersonaje;
}

int Personaje::getsetVida()
{
	return vida;
}

int Personaje::getAtaque()
{
	return ataque;
}

int Personaje::getposicionX()
{
	return posicionX;
}

int Personaje::getposicionY()
{
	return posicionY;
}

int Personaje::getposicionInicialX()
{
	return posicionInicialX;
}

int Personaje::getposicionInicialY()
{
	return posicionInicialY;
}





void Personaje::printStatus()
{
	cout << "Nuestro heroe se llama " << getNombrePersonsaje() << " y tiene una vida de " << getsetVida() << endl;
}



