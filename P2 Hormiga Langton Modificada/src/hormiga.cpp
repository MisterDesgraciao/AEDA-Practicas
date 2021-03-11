/* Universidad de La Laguna.
  Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

  Práctica 2. La hormiga de Langton Modificada.
  La hormiga de Langton es un sistema discreto, determinista y muy simple. Esto es, dado un estado inicial en el paso de tiempo 0 se define el estado 
  en el paso de tiempo 1, y así sucesivamente. La versión clásica funciona sobre un «mundo» que es una malla cuadriculada bidimensional infinita, para esta versión modificada.

  Enunciado completo en: https://campusingenieriaytecnologia.ull.es/pluginfile.php/334688/mod_resource/content/15/AEDA-pract02.pdf

  Realizado por: Óscar Ignacio Pozo Fernández.
  Correo: alu0101036526@ull.edu.es

  Compilar con: g++ -std=c++17 -o MundoHormiga main.cpp universo.cpp hormiga.cpp mundo.cpp
  o 
  Makefile: make clean -> make.
*/
#include <iostream>
#include <string>
#include <stdlib.h> //Para exit(), que es cuando falla el programa.

#include "../include/hormiga.hpp"

using namespace std;

// Constructor por defecto que usa las posiciones iniciales de la Hormiga por defecto.
Hormiga::Hormiga(Mundo &MundoInsecto) {
  MundoInsecto.setPosicionHormiga(valorY, valorX, '^');
  MundoInsecto.actualizarPosicionHormiga(valorY, valorX);
}

// Constructor que asigna a la Hormiga la posición inicial designada por el usuario.
Hormiga::Hormiga(Mundo &MundoInsecto, int valorYinicial, int valorXinicial) {
  valorY = valorYinicial;
  valorX = valorXinicial;
  MundoInsecto.setPosicionHormiga(valorY, valorX, '^');
  MundoInsecto.actualizarPosicionHormiga(valorY, valorX);
}

// Desatructor
Hormiga::~Hormiga() {}

/*  Función que tiene todas las reglas de la Hormiga.
*   Primero valora el contenido de la celda en la que está la Hormiga.
*   Después selecciona la opción que se corresponde a la casilla 
*   y a la dirección a la que mira actualmente la hormiga.
*   En esta función se actualizan la posición y el mensaje de la Hormiga,
*   además de llamar a expandirMalla() si se avanza más allá de un límite de la matriz.
*/
void Hormiga::reglasHormiga(Mundo &MundoInsecto) {
  Posicion posicionHormiga = MundoInsecto.getPosicionHormiga();
  int limiteSuperior = MundoInsecto.getNumFilas() - 1;
  int limiteInferior = MundoInsecto.getNumColumnas() - 1;
  int limiteIzquierdo = 0;
  int limiteDerecho = 0;
  int posY = posicionHormiga.posY;
  int posX = posicionHormiga.posX;

  if (MundoInsecto.getValorCelda(posY, posX) == ' ') {
    MundoInsecto.setValorCelda(posY, posX, 'X');
    switch (direccionActual) {
      case 8 :                // 8 = Norte
        direccionActual = 7;  // 7 = Noroeste
        if (posY == limiteSuperior && posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(7);
          MundoInsecto.setPosicionHormiga(posY + 1, posX, '7');
        } else if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
          MundoInsecto.setPosicionHormiga(posY + 1, posX - 1, '7');
        } else if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY + 1, posX, '7');
        } else {
          MundoInsecto.setPosicionHormiga(posY + 1, posX - 1, '7');
        }
        MundoInsecto.actualizarPosicionHormiga(1, -1);
      break;
      case 7 :                // 7 = Noroeste
        direccionActual = 4;  // 4 = Oeste
        if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY, posX, '4');
        } else {
          MundoInsecto.setPosicionHormiga(posY, posX - 1, '4');
        }
        MundoInsecto.actualizarPosicionHormiga(0, -1);
      break;
      case 4 :                // 4 = Oeste
        direccionActual = 1;  // 1 = Suroeste
        if (posY == limiteInferior && posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(1);
          MundoInsecto.setPosicionHormiga(posY, posX, '1');
        } else if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY, posX - 1, '1');
        } else if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY - 1, posX, '1');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX - 1, '1');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, -1);
      break;
      case 1 :                // 1 = Suroeste
        direccionActual = 2;  // 2 = Sur
        if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY - 1, posX, '2');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX, '2');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, 0);
        break;
      case 2 :                // 2 = Sur
        direccionActual = 3;  // 3 = Sureste
        if (posY == limiteInferior && posX == limiteDerecho) {
          MundoInsecto.expandirMalla(3);
          MundoInsecto.setPosicionHormiga(posY, posX + 1, '3');
        } else if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY, posX + 1, '3');
        } else if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
          MundoInsecto.setPosicionHormiga(posY - 1, posX + 1, '3');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX + 1, '3');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, 1);
        break;
      case 3 :                // 3 = Sureste
        direccionActual = 6;  // 6 = Este
        if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
        }
        MundoInsecto.setPosicionHormiga(posY, posX + 1, '6');
        MundoInsecto.actualizarPosicionHormiga(0, 1);
        break; 
      case 6 :                // 6 = Este
        direccionActual = 9;  // 9 = Noreste
        if (posY == limiteSuperior && posX == limiteDerecho) {
          MundoInsecto.expandirMalla(9);
        } else if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
        } else if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
        }
        MundoInsecto.setPosicionHormiga(posY + 1, posX + 1, '9');
        MundoInsecto.actualizarPosicionHormiga(1, 1);
      break;
      case 9 :                // 9 = Noreste
        direccionActual = 8;  // 8 = Norte
        if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
        }
        MundoInsecto.setPosicionHormiga(posY + 1, posX, '8');
        MundoInsecto.actualizarPosicionHormiga(1, 0);
      break;
      default:
        cout << "ERROR 5. No se sabe la dirección de la hormiga." << endl;
        exit(5);
      break;
    }
  } else if (MundoInsecto.getValorCelda(posY, posX) == 'X') {
    MundoInsecto.setValorCelda(posY, posX, ' ');
    switch (direccionActual) {
      case 8 :                // 8 = Norte
        direccionActual = 9;  // 9 = Noreste
        if (posY == limiteSuperior && posX == limiteDerecho) {
          MundoInsecto.expandirMalla(9);
        } else if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
        } else if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
        }
        MundoInsecto.setPosicionHormiga(posY + 1, posX + 1, '9');
        MundoInsecto.actualizarPosicionHormiga(1, 1);
      break;
      case 9 :                // 9 = Noreste
        direccionActual = 6;  // 6 = Este
        if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
        }
        MundoInsecto.setPosicionHormiga(posY, posX + 1, '6');
        MundoInsecto.actualizarPosicionHormiga(0, 1);
      break;
      case 6 :                // 6 = Este
        direccionActual = 3;  // 3 = Sureste
        if (posY == limiteInferior && posX == limiteDerecho) {
          MundoInsecto.expandirMalla(3);
          MundoInsecto.setPosicionHormiga(posY, posX + 1, '3');
        } else if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY, posX + 1, '3');
        } else if (posX == limiteDerecho) {
          MundoInsecto.expandirMalla(6);
          MundoInsecto.setPosicionHormiga(posY - 1, posX + 1, '3');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX + 1, '3');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, 1);
      break;
      case 3 :                // 3 = Sureste
        direccionActual = 2;  // 2 = Sur
        if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY, posX, '2');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX, '2');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, 0);
        break;
      case 2 :                // 2 = Sur
        direccionActual = 1;  // 1 = Suroeste
        if (posY == limiteInferior && posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(1);
          MundoInsecto.setPosicionHormiga(posY, posX, '1');
        } else if (posY == limiteInferior) {
          MundoInsecto.expandirMalla(2);
          MundoInsecto.setPosicionHormiga(posY, posX - 1, '1');
        } else if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY - 1, posX, '1');
        } else {
          MundoInsecto.setPosicionHormiga(posY - 1, posX - 1, '1');
        }
        MundoInsecto.actualizarPosicionHormiga(-1, -1);
        break;
      case 1 :                // 1 = Suroeste
        direccionActual = 4;  // 4 = Oeste
        if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY, posX, '4');
        } else {
          MundoInsecto.setPosicionHormiga(posY, posX - 1, '4');
        }
        MundoInsecto.actualizarPosicionHormiga(0, -1);
        break; 
      case 4 :                // 4 = Oeste
        direccionActual = 7;  // 7 = Noroeste
        if (posY == limiteSuperior && posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(7);
          MundoInsecto.setPosicionHormiga(posY + 1, posX, '7');
        } else if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
          MundoInsecto.setPosicionHormiga(posY + 1, posX - 1, '7');
        } else if (posX == limiteIzquierdo) {
          MundoInsecto.expandirMalla(4);
          MundoInsecto.setPosicionHormiga(posY + 1, posX, '7');
        } else {
          MundoInsecto.setPosicionHormiga(posY + 1, posX - 1, '7');
        }
        MundoInsecto.actualizarPosicionHormiga(1, -1);
      break;
      case 7 :                // 7 = Noroeste
        direccionActual = 8;  // 8 = Norte
        if (posY == limiteSuperior) {
          MundoInsecto.expandirMalla(8);
        }
        MundoInsecto.setPosicionHormiga(posY + 1, posX, '8');
        MundoInsecto.actualizarPosicionHormiga(1, 0);
      break;
      default:
        cout << "ERROR 6. No se sabe la dirección de la hormiga." << endl;
        exit(5);
      break;
    }
  }
}
