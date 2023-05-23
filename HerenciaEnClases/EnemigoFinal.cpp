#include "EnemigoFinal.h"
#include <iostream>

// Constructor
EnemigoFinal::EnemigoFinal(string pNombrePersonaje, int pVida, int pAtaque, int pPosicionX, int pPosicionY, bool pFireAttack, int pFrozenAttack, int pShield)
	: Personaje(pNombrePersonaje, pVida, pAtaque, pPosicionX, pPosicionY) {
	fireAttack = pFireAttack;
	frozenAttack = pFrozenAttack;
	shield = pShield;
}

// Getters
int EnemigoFinal::getFireAttack()
{
    return fireAttack;
}

int EnemigoFinal::getFrozenAttack()
{
    return frozenAttack;
}


// Setters
void EnemigoFinal::setFireAttack(int pFireAttack)
{
    fireAttack = pFireAttack;
}

void EnemigoFinal::setFrozenAttack(int pFrozenAttack)
{
    frozenAttack = pFrozenAttack;
}

