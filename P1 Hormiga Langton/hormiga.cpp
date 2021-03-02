/* Universidad de La Laguna.
  Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

  Práctica 1. La hormiga de Langton.
  La hormiga de Langton es un sistema discreto, determinista y muy simple. Esto es, dado un estado inicial en el paso de tiempo 0 se define el estado 
  en el paso de tiempo 1, y así sucesivamente. La versión clásica funciona sobre un «mundo» que es una malla cuadriculada bidimensional. 
  En principio se supone infinita, aunque por razones prácticas, se hacen simulaciones donde el borde superior de la malla se identifica con el inferior,
  y el borde izquierdo con el derecho.

  Enunciado completo en: https://campusingenieriaytecnologia.ull.es/pluginfile.php/334685/mod_resource/content/18/AEDA-pract01.pdf

  Compilar con: g++ -std=c++17 -o MundoHormiga main.cpp hormiga.cpp mundo.cpp
*/
#include <iostream>
#include <string>
#include <stdlib.h> //Para exit(), que es cuando falla el programa.

#include "hormiga.hpp"

using namespace std;

Hormiga::Hormiga() {
  Mundo MundoInsecto;
  valorYinicial = 1;
  valorXinicial = 1;
  MundoInsecto.setPosicionHormiga(valorYinicial, valorXinicial, '^');
  MundoInsecto.mostrarMundo();
  for (int iterador = 0; iterador < 3; iterador++) {
    reglasHormiga(MundoInsecto);
  }
}

Hormiga::~Hormiga() {}


void Hormiga::reglasHormiga(Mundo &MundoInsecto) {
  Posicion posicionHormiga = MundoInsecto.getPosicionHormiga();
  int limiteSuperior = 1;
  int limiteInferior = MundoInsecto.getNumColumnas() - 2;
  int limiteLateralIzquierdo = 1;
  int limiteLateralDerecho = MundoInsecto.getNumFilas() - 2;

  if (MundoInsecto.getValorCelda(posicionHormiga.posY, posicionHormiga.posX) == ' ') {
    switch (direccionActual) {
      case 'n' :
        cout << "Se desplaza al oeste." << endl;
        direccionActual = 'w';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, 'X');
        if (posicionHormiga.posX == limiteLateralIzquierdo) {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, limiteLateralDerecho, '<');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, posicionHormiga.posX - 1, '<');
        }
      break;
      case 'w' :
        cout << "Se desplaza al sur." << endl;
        direccionActual = 's';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, 'X');
        if (posicionHormiga.posY == limiteInferior) {
          MundoInsecto.setPosicionHormiga(limiteSuperior, posicionHormiga.posX, 'v');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY + 1, posicionHormiga.posX, 'v');
        }
      break;
      case 's' :
        cout << "Se desplaza al este." << endl;
        direccionActual = 'e';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, 'X');
        if (posicionHormiga.posX == limiteLateralDerecho) {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, limiteLateralIzquierdo, '>');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, posicionHormiga.posX + 1, '>');
        }
      break;      
      case 'e' :
        cout << "Se desplaza al norte." << endl;
        direccionActual = 'n';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, 'X');
        if (posicionHormiga.posY == limiteSuperior) {
          MundoInsecto.setPosicionHormiga(limiteInferior, posicionHormiga.posX, '^');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY - 1, posicionHormiga.posX, '^');
        }
      break;
      default:
        cout << "ERROR 5. No se sabe la dirección de la hormiga." << endl;
        exit(5);
      break;
    }
  } else if (MundoInsecto.getValorCelda(posicionHormiga.posY, posicionHormiga.posX) == 'X') {
    switch (direccionActual) {
      case 'n' :
        cout << "Se desplaza al este." << endl;
        direccionActual = 'e';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, ' ');
        if (posicionHormiga.posX == limiteLateralDerecho) {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, limiteLateralIzquierdo, '>');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, posicionHormiga.posX + 1, '>');
        }
      break;
      case 'e' :
        cout << "Se desplaza al sur." << endl;
        direccionActual = 's';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, ' ');
        if (posicionHormiga.posY == limiteInferior) {
          MundoInsecto.setPosicionHormiga(limiteSuperior, posicionHormiga.posX, 'v');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY + 1, posicionHormiga.posX, 'v');
        }
      break;
      case 's' :
        cout << "Se desplaza al oeste." << endl;
        direccionActual = 'w';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, ' ');
        if (posicionHormiga.posX == limiteLateralIzquierdo) {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, limiteLateralDerecho, '<');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY, posicionHormiga.posX - 1, '<');
        }
      break;      
      case 'w' :
        cout << "Se desplaza al norte." << endl;
        direccionActual = 'n';
        MundoInsecto.setValorCelda(posicionHormiga.posY, posicionHormiga.posX, ' ');
        if (posicionHormiga.posY == limiteSuperior) {
          MundoInsecto.setPosicionHormiga(limiteInferior, posicionHormiga.posX, '^');
        } else {
          MundoInsecto.setPosicionHormiga(posicionHormiga.posY - 1, posicionHormiga.posX, '^');
        }
      break;
      default:
        cout << "ERROR 5. No se sabe la dirección de la hormiga." << endl;
        exit(5);
      break;
    }
  /*  //Modificación si piden usar otros dos colores para las casillas, con sus respectivas reglas
  } else if (MundoInsecto.getValorCelda(posicionHormiga.posY, posicionHormiga.posX) == 'O') {     //Color Rojo
    switch() {

    }
  } else if (MundoInsecto.getValorCelda(posicionHormiga.posY, posicionHormiga.posX) == 'L') {     //Color Azul
    switch() {

    }
  */
  }
  MundoInsecto.mostrarMundo();
}
