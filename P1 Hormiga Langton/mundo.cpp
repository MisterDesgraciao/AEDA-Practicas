/* Universidad de La Laguna.
    Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

*/
#include <iostream>
#include <string>

#include "mundo.hpp"

using namespace std;

// Por defecto nos indican que el mundo está vacío. Así que lo rellenamos con espacios por si acaso.
Mundo::Mundo() {
  crearMundo();
}

Mundo::Mundo(int altoMundo, int anchoMundo) {
  numFilas = altoMundo;
  numColumnas = anchoMundo;
  crearMundo();
}

Mundo::~Mundo(){}

int Mundo::getNumFilas() {
  return numFilas;
}

int Mundo::getNumColumnas() {
  return numColumnas;
}

void Mundo::setValorCelda(int celdaY, int celdaX, char valor) {
  celdasMundo[celdaY][celdaX] = valor;
}

void Mundo::crearMundo() {
  for (int iteradorY = 0; iteradorY < numFilas; iteradorY++) {
    for (int iteradorX = 0; iteradorX < numColumnas; iteradorX++) {
      setValorCelda(iteradorY, iteradorX, ' ');
    }
  }
  crearBordes();
}

char Mundo::getValorCelda(int valorY, int valorX) {
  return celdasMundo[valorY][valorX];
}

void Mundo::mostrarMundo() {
    for (int iteradorY = 0; iteradorY < numFilas; iteradorY++) {
      for (int iteradorX = 0; iteradorX < numColumnas; iteradorX++) {
        if (iteradorY == posicionHormiga.posY && iteradorX == posicionHormiga.posX) {
          cout << iconoHormiga;
        } else {
          cout << celdasMundo[iteradorY][iteradorX];          
        }
      }
      cout << endl;
  }   
  cout << "La Hormiga se encuentra en la posición: " << posicionHormiga.posY << "," << posicionHormiga.posX << endl;
}

void Mundo::crearBordes() {
  for (int iteradorY = 0; iteradorY <= numFilas; iteradorY++) {
    for (int iteradorX = 0; iteradorX <= numColumnas; iteradorX++) {
      if (iteradorY == 0 || iteradorY == numFilas - 1) {
        setValorCelda(iteradorY, iteradorX, '-');
      } else {
        if (iteradorX == 0 || iteradorX == numColumnas - 1) {
          setValorCelda(iteradorY, iteradorX, '|');
        }
      }
    }
  }
}

void Mundo::setPosicionHormiga(int valorY, int valorX, char icono) {
  posicionHormiga = {valorY, valorX};
  iconoHormiga = icono;
  //setValorCelda(valorY, valorX, '@');
}

Posicion Mundo::getPosicionHormiga() {
  return posicionHormiga;
}

