#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;



int main() {
    
    // Creación del tablero y colocación del personaje inicialmente
    const int filas = 10;
    const int columnas = 5;
    char mapa[filas][columnas];

    int posicionInicialX = 2;
    int posicionInicialY = 0;
    Personaje heroe("John Wick", 100, 10, posicionInicialX, posicionInicialY);

    // Genera posición aleatoria para la salida
    int salidaX = rand() % columnas;
    int salidaY = filas - 1;

    // Generar posición aleatoria para el enemigo final
    int enemigoFinalX = rand() % columnas;
    int enemigoFinalY = rand() % filas;  

    // Posicionamiuento del Heroe, el Enemigo y la Salida
    mapa[heroe.getposicionY()][heroe.getposicionX()] = 'H';
    mapa[salidaY][salidaX] = 'S';
    mapa[enemigoFinalY][enemigoFinalX] = 'E';
  
    char comando;
    bool juegoTerminado = false;

    while (!juegoTerminado) {
        // Mostra el estado actual del tablero
        cout << "-------- Mapa --------" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << mapa[i][j] << "    ";
            }
            cout << endl;
        }
        cout << "----------------------" << endl;

        // Mostra el estado actual del personaje
        cout << "Estado del personaje:" << endl;
        heroe.printStatus();
        cout << endl;

       
        cout << "Ingrese un comando (w: arriba, a: izquierda, s: abajo, d: derecha, q: salir): ";
        cin >> comando;

        // Mover al personaje según el comando
        int nuevaPosX = heroe.getposicionX();
        int nuevaPosY = heroe.getposicionY();

        switch (comando) {
        case 'w':
            nuevaPosY--;
            break;
        case 'a':
            nuevaPosX--;
            break;
        case 's':
            nuevaPosY++;
            break;
        case 'd':
            nuevaPosX++;
            break;
        case 'q':
            juegoTerminado = true;
            cout << "¡Juego terminado!" << endl;
            break;
        default:
            cout << "Comando inválido. Intente de nuevo." << endl;
            continue;
        }

        
        if (nuevaPosX >= 0 && nuevaPosX < columnas && nuevaPosY >= 0 && nuevaPosY < filas) {
            // Actualiza la posición del personaje en el tablero
            mapa[heroe.getposicionY()][heroe.getposicionX()] = '-';

       
            heroe.setPosicionX(nuevaPosX);
            heroe.setPosicionY(nuevaPosY);

            // Colocar al personaje en su nueva posición en el tablero
            mapa[heroe.getposicionY()][heroe.getposicionX()] = 'H';

                // Verifica si el personaje ha llegado a la salida
                if (heroe.getposicionX() == salidaX && heroe.getposicionY() == salidaY) {
                    cout << "¡Has alcanzado la salida! ¡Has ganado el juego!" << endl;
                    juegoTerminado = true;
                }

            // Verificar si el personaje ha encontrado al enemigo final
            if (heroe.getposicionX() == enemigoFinalX && heroe.getposicionY() == enemigoFinalY) {
                cout << "¡Has encontrado al enemigo final!" << endl;
                juegoTerminado = true;
            }
        }
        else {
            cout << "Movimiento inválido. Intente de nuevo." << endl;
        }
    }


        return 0;
 }