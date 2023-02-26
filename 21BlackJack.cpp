#include <iostream> /*librería que proporciona herramientas para la entrada y salida de datos, en particular los objectos "cin" y "cout".*/
#include <stdlib.h> /*librería para la función rand() para generar numeros aleatorias*/
#include <time.h> /*librería  para la obtención de la fecha y hora actual, la manipulación de estructuras de tiempo para realizar operaciones como sumar o restar*/
#include <sstream> /*librería que proporciona herramientas para trabajar con cadenas de caracteres (string) En particular, proporciona la clase "stringstream"*/
#include <windows.h> /*librería de programación para el sistema operativo windows, que proporciona una amplica variedad de funciones para trabajar. */


using namespace std;
// Baraja inglesa de 52 cartas que se agrupan en 4 palos de 13 cartas cada uno:
// -Corazones (Hearts)
// -Picas (Spades)
// -Diamantes (Diamonds)
// -Tréboles (Clubs)

// -Variables de cartas. Por cada palo 13 posiciones de arrays
string Corazones[13] = { "AS", "2","3","4","5","6","7","8","9","10","J","Q","K" };
string Picas[13] = { "AS", "2","3","4","5","6","7","8","9","10","J","Q","K" };
string Diamantes[13] = { "AS", "2","3","4","5","6","7","8","9","10","J","Q","K" };
string Treboles[13] = { "AS", "2","3","4","5","6","7","8","9","10","J","Q","K" };


// -Variables jugador 1
string jugador1 = "";
int puntosJugador1 = 0;
string cartasJugador1[13]; // guarda las cartas del jugador

// -Variables jugador 2
string jugador2 = "Croupier";
int puntosJugador2 = 0;
string cartasJugador2[13]; //guarda las cartas del croupier


/*Las variables int "cJugador1" y "cJugador2" se inicializan con los valores 2 y 1 respectivamente, 
mientras que las variables "caJugador1" y "caJugador2" se inicializan con el valor 0.*/
stringstream ss;
int cJugador1 = 2;
int cJugador2 = 1;
int caJugador1 = 0;
int caJugador2 = 0;


/*Esta función "compruebapuntos" imprime en la salida estándar los puntos de dos jugadores, 
con el fin de que el jugador pueda conocer la puntuación de los jugadores y tomar decisiones.*/
void compruebapuntos() {
    cout << jugador1 << " tus puntos son: " << puntosJugador1 << "\n";
    cout << "Los puntos del croupier son: " << puntosJugador2 << "\n";
}

/*Esta función "carta" toma un paraámetro de entrada "stringreceptor" que devuelve una cadeca de caracteres,
en este caso jugador1 o croupier.*/
string carta(string stringreceptor) {
    int p = (rand() % 4) + 1; /*número aleatorio entre 1 y 4 que "p" representa palo.*/
    int n = rand() % 13; /*número aleatorio entre 0 y 12 que "n" representa el número/valor de la carta.*/
    string carta;
    string palo;
    int contador = 1; 
    int c1 = 0;


    bool repite = true;
    while (repite) { /*Bucle que se utilizar para generar una carta aleatoria y asegurarse de que no se generen cartas repetidas. */
        switch (p) {

        case 1: 
            palo = "corazones";

            while (Corazones[n] == "repetido") {
                int p = c1;
                c1++;
                contador++;
                if (contador == 13) {
                    p = rand() % 4 + 1;
                    break;
                }
            }
            if (contador == 13) {
                contador = 1;
                c1 = 0;
                break;
            }
            carta = Corazones[n];
            Corazones[n] = "repetido";
            repite = false;
            break;

        case 2:
            palo = "diamantes";
            while (Diamantes[n] == "repetido") {
                int p = c1;
                c1++;
                contador++;
                if (contador == 13) {
                    p = rand() % 4 + 1;
                    c1 = 0;
                    break;
                }
            }
            if (contador == 13) {
                contador = 1;
                break;
            }
            carta = Diamantes[n];
            Diamantes[n] = "repetido";
            repite = false;
            break;

        case 3:
            palo = "picas";
            while (Picas[n] == "repetido") {
                int p = c1;
                c1++;
                contador++;
                if (contador == 13) {
                    c1 = 0;
                    p = rand() % 4 + 1;
                    break;
                }
            }
            if (contador == 13) {
                contador = 1;
                break;
            }
            carta = Picas[n];
            Picas[n] = "repetido";
            repite = false;
            break;

        case 4:
            palo = "treboles";
            while (Treboles[n] == "repetido") {
                int p = c1;
                c1++;
                contador++;
                if (contador == 13) {
                    p = rand() % 4 + 1;
                    c1 = 0;
                    break;
                }
            }
            if (contador == 13) {
                contador = 1;
                break;
            }
            carta = Treboles[n];
            Treboles[n] = "repetido";
            repite = false;
            break;

        }

    }
    string aux = carta; 
    if (stringreceptor == "croupier") {

        if (aux == "AS") { /*crea una copia de la carta recibida para el croupier y se almacena en la variable "aux", se evalúa si la carta es un as,
                           ya que valor puede ser tanto 1 como 11. Si al sumar 11 a los puntos supera los 21 entonces el AS valdrá 1 en caso contrario 
                           se le da un valor de 11.*/
            if (11 + puntosJugador2 > 21) {
                aux = "1";
            }
            else {
                aux = "11";
            }
        }
        else if (aux == "Q" || aux == "K" || aux == "J") { /*Si la carta no es un AS, entonces se verifica si es un Q,K,J, si es así se le da un valor de 10*/
            aux = "10";
        }
        puntosJugador2 += stoi(aux); /*Se suma el valor de la carta (que está almacenado en la variable "aux", y que puede ser un string o un número) 
                                     a los puntos totales del jugador2, que se van ocumulando en la variable "puntosJugador2"*/
        caJugador2++; /*Incrementa en uno el número de cartas que ha recibido el croupier en su mano actual.*/
    }
    else if (stringreceptor == "jugador1") { /*Opción para el jugador1 si le sale un AS puede elegir si vale un 1 o 11*/
        if (aux == "AS") {
            string opcion = "";
            while (opcion != "1" && opcion != "11") {
                cout << "Te ha salido un AS, Que valor quieres que valga, 1 o 11?";
                cin >> opcion;
            }
            if (opcion == "11") {
                aux = "11";
            }
            else {
                aux = "1";
            }
        }
        else if (aux == "Q" || aux == "K" || aux == "J") {
            aux = "10";
        }
        puntosJugador1 += stoi(aux); /*Suma el valor de la carta que está almacenada en la variable "aux" y que puede ser un número o un string correspondiente a la carta especial,
                                     a los puntos totales del jugador1, que se van acumulando en la variable "puntosJugador1*/
        caJugador1++;
    }

    return (carta + " de " + palo);
}



void inicio() { /*Inicializa el juego estableciendo las cartas para el juegador1 y jugador2*/
    for (int i = 0; i < 13; i++) {
        cartasJugador1[i] = "NADA"; /*incializa l'array de cartas del jugador1 y del jugador2, asignando "NADA" a cada una de las 13 posiciones.*/
        cartasJugador2[i] = "NADA";
    }
    cartasJugador1[0] = carta("jugador1"); /*Se le llama a la función "carta" para obtener las cartas*/
    cartasJugador1[1] = carta("jugador1");
    cartasJugador2[0] = carta("croupier");
    cout << "El croupier te reparte 2 cartas y 1 para el.\nTus dos cartas son:\nCarta 1: " << cartasJugador1[0] << "\nCarta 2: " << cartasJugador1[1] << "\n";
    cout << "La carta del croupier: " << cartasJugador2[0] << "\n";
}


/*Función "juego"*/
void juego() { 
    bool pidiendo = true; 
    while (pidiendo && puntosJugador1 <= 21) {  /*Mientras "pidiendo" sea verdadero y los puntos del jugador1 sean menores o iguales a 21,
                                                se pregunta al jugador si quiere pedir más cartas.*/
        cout << "Quieres pedir mas cartas?\nSI \tNO";
        cout << "\n";
        string eleccion;
        cin >> eleccion;
        if (eleccion == "si" || eleccion == "SI") { /*Si el jugador responde con un si o SI llama a la función "carta" para obtener una nueva carta
                                                    y se le agrega al array "cartasJugador1. Luego se aumenta el contador "cJugador1". */
            cartasJugador1[cJugador1] = carta("jugador1"); 
            cout << "La carta que has recibido es " << cartasJugador1[cJugador1] << "\n";
            cJugador1++;
            compruebapuntos(); 
        }
        else {
            pidiendo = false; /*si el jugador responde con un no, se sale del bucle.*/
        }
    }
    if (puntosJugador1 > 21) { 
        cout << "Te has pasado de 21. Gana el croupier." << "\n";
    }
    else { 
        while (puntosJugador2 < puntosJugador1 && puntosJugador2 != 21) {
            cartasJugador2[cJugador2] = carta("croupier");  
            cout << "La carta que ha recibido el croupier es " << cartasJugador2[cJugador2] << "\n";
            cJugador2++;
            compruebapuntos(); 
        }
    }
}


void finpartida() { 
    if (puntosJugador1 > 21) {}
    else {
        cout << "El croupier tiene " << puntosJugador2 << "!\n";
        if (puntosJugador2 > 21 || puntosJugador2 < puntosJugador1) { 
            cout << "Has ganado la partida!\n";
        }
        else if (puntosJugador2 == puntosJugador1) {
            cout << "Habeis empatado!\n";
        }
        else if (puntosJugador2 > puntosJugador1) {
            cout << "Gana el croupier!\n";
        }
    }
}

int main(void) {

    cout << "===========================================================================" << endl;
    cout << "=                               21 BLACKJACK                              =" << endl;
    cout << "=                                Bienvenido                               =" << endl;
    cout << "===========================================================================" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "Nombre del jugador? ";
    cin >> jugador1;
    cout << "\n";
    cout << jugador2 << ": Mucha suerte " << jugador1 << "!!" << endl;

    srand(time(NULL));
    inicio();
    compruebapuntos();
    juego();
    finpartida();
}

