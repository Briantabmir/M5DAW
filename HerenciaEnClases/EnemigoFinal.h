#pragma once
#include "Personaje.h"

#include <iostream>

using namespace std;


//Heredamos de la clase Personaje al EnemigoFinal
class EnemigoFinal : public Personaje {

private:
	int fireAttack;
	int frozenAttack;
	int shield; //escudo

public:
	//constructor con elementos de la clase Personaje
	EnemigoFinal(string pNombrePersonaje, int pVida, int pAtaque, int pPosicionX, int pPosicionY, bool pFireAttack, int pFrozenAttack, int pShield);

	//Getters
	int getFireAttack();
	int getFrozenAttack();

	//Setters
	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);

	//Crear métodos propios
	// void printAllStats();
};

