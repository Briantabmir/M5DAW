#pragma once
#include <iostream>
using namespace std;


class Personaje		// Clase Personaje
{
private:	   // Atributos del Personaje

	string nombrePersonaje;
	int vida;
	int ataque;
	int posicionX;
	int posicionY;
	int posicionInicialX;
	int posicionInicialY;

public:

	//Constructor
	Personaje(string pNombrePersonaje, int pVida, int pAtaque, int pPosicionInicialX, int pPosicionInicialY);


	// Setter (modifica el valor de los atributos privados del Personaje)
	void setNombrePersonaje(string pNombrePersonaje);
	void setVida(int pVida);
	void setAtaque(int pAtaque);
	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);
	void setPosicionInicialX(int pPosicionInicialX);
	void setPosicionInicialY(int pPosicionInicialY);

	// Getters (obtiene o devuelve el valor de un atributo de la clase)

	string getNombrePersonsaje();
	int getsetVida();
	int getAtaque();
	int getposicionX();
	int getposicionY();
	int getposicionInicialX();
	int getposicionInicialY();


	//Crear métodos propios
	void printStatus();


};