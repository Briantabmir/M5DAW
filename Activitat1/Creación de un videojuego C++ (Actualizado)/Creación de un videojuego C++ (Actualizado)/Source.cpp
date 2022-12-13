#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
//librerias

using namespace std;

//Atributo del enemigo1
int enemyDamage1;
int enemyHP1 = 100;
string enemyName1 = "Katarina";
bool enemyIsAlive1 = true;

//Atributo del enemigo2
int enemyDamage2;
int enemyHP2 = 100;
string enemyName2 = "Lux";
bool enemyIsAlive2 = true;

//Atributo de heroe
int heroDamage;
int heroHP = 150;
string heroName = "Ziggs";
bool heroIsAlive = true;


void StartGame() {
	cout << "Acaba de aparecer dos enemigas, son " << enemyName1 << " y " << enemyName2 << ", parecen tener 100 HP cada una.\n";
	cout << "Para el combate, como quieres que se llame tu heroe? ";
	cin >> heroName;

	cout << "A quien quieres atacar?" "\n";
}

int heroAttack1() {
	return enemyHP1 - heroDamage;
}

int heroAttack2() {
	return enemyHP2 - heroDamage;
}



bool heroIsalive() {
	if (enemyIsAlive1 && enemyIsAlive2) {
		heroHP = heroHP - enemyDamage1;
		if (heroHP <= 0) {
			heroHP = 0;
			cout << "El enemigo " << enemyName1 << " te ha matado\n";
			heroIsAlive = false;
		}
		else {
			cout << "El enemigo " << enemyName1 << " te ha atacado con " << enemyDamage1 << " puntos de danyo. Tienes " << heroHP << " HP\n";

		}

		heroHP = heroHP - enemyDamage2;
		if (heroHP <= 0) {
			heroHP = 0;
			cout << "El enemigo " << enemyName2 << " te ha matado\n";
			heroIsAlive = false;
		}
		else {
			cout << "El enemigo " << enemyName2 << " te ha atacado con " << enemyDamage2 << " puntos de danyo. Tienes " << heroHP << " HP\n";
			return true;
		}

	}
}

bool enemyIsAlivE() {
	if (!enemyIsAlive1 && enemyIsAlive2) {
		heroHP = heroHP - enemyDamage2;
		if (heroHP <= 0) {
			heroHP = 0;
			cout << "El enemigo " << enemyName2 << " te ha matado\n";
			heroIsAlive = false;
		}
		else {
			cout << "El enemigo " << enemyName2 << " te ha atacado con " << enemyDamage2 << " puntos de danyo. Tienes " << heroHP << " HP\n";
			return true;
		}
	}
}

bool enemyIs_AlivE() {
	if (!enemyIsAlive2 && enemyIsAlive1) {
		heroHP = heroHP - enemyDamage1;
		if (heroHP <= 0) {
			heroHP = 0;
			cout << "El enemigo " << enemyName1 << " te ha matado\n";
			heroIsAlive = false;
		}
		else {
			cout << "El enemigo " << enemyName1 << " te ha atacado con " << enemyDamage1 << " puntos de danyo. Tienes " << heroHP << " HP\n";
			return true;
		}
	}
}

//opcion de ataque
void ataques() {
	cout << "Elige un ataque: " << endl;
	cout << "1) Puñetazo" << endl;
	cout << "2) Espada" << endl;
	cout << "3) Magia" << endl;
}

int main() {
	//Sonido del juego
	PlaySound(TEXT("Battle.wav"), NULL, SND_LOOP | SND_ASYNC);

	//Empieza el juego
	srand(time(NULL));
	
	StartGame();

	int opcion = 0;
	//Daño aleatorio
	while (heroIsAlive && (enemyIsAlive1 || enemyIsAlive2)) {
		enemyDamage1 = 5 + rand() % 10;
		enemyDamage2 = 5 + rand() % 10;

		// Muestra los dos enemigos estan vivos o uno de los dos dependiendo si está vivo o muerto
		if (enemyIsAlive1 && enemyIsAlive2) {
			cout << " 1)" << enemyName1 << " o " "2) " << enemyName2 << "\n";
		}
		if (!enemyIsAlive1 && enemyIsAlive2) {
			cout << "2) " << enemyName2 << "\n";
		}
		if (enemyIsAlive1 && !enemyIsAlive2) {
			cout << " 1)" << enemyName1 << "\n";
		}
		
		cin >> opcion;
		ataques();


		


		//Elegir qué enemigo queremos atacar y cuanto daño se quiere hacer y muestra si lo hemos matado
		switch (opcion) {
		case 1:

			if (enemyIsAlive1) {
				
				/*cout << "Marca la cantidad de danyo que quieres dar \n";*/
				
				/*cin >> heroDamage;*/
				/*enemyHP1 = heroAttack1();*/
				if (enemyHP1 <= 0) {
					cout << "Acabas de matar a " << enemyName1 << "!!!\n";
					enemyIsAlive1 = false;
				}
				else {
					cout << enemyName1 << " le queda " << enemyHP1 << " HP\n";
				}
			}
			else {
				cout << "Has fallado \n";
			}

			break;

		case 2:
			if (enemyIsAlive2) {
				cout << "Marca la cantidad de danyo que quieres dar \n";
				cin >> heroDamage;
				enemyHP2 = heroAttack2();
				if (enemyHP2 <= 0) {
					cout << "Acabas de matar a " << enemyName2 << "!!!\n";
					enemyIsAlive2 = false;
				}
				else {
					cout << enemyName2 << " le queda " << enemyHP2 << " HP\n";
				}
			}
			else {
				cout << "Has fallado \n";
			}
			break;
		default:
			cout << "No has elegido un enemigo \n";
			break;

		}

		//El enemigo ataca hasta que mueras
		heroIsalive();

		//Si uno de los dos está muerto el otro sigue atacando
		enemyIsAlivE();
		enemyIs_AlivE();
		
	}

}