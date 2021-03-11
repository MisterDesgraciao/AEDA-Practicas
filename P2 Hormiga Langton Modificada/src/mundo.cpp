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

#include "../include/mundo.hpp"

using namespace std;

// Constructor por defecto, con unos valores preestablecidos por mi.
Mundo::Mundo() {
  numFilas = 10;
  numColumnas = 10;
  crearMundo(numFilas, numColumnas);
}

// Constructor que recibe los parámetros indicados por el usuario para construir el Mundo.
Mundo::Mundo(int altoMundo, int anchoMundo) {
  numFilas = altoMundo;
  numColumnas = anchoMundo;
  crearMundo(altoMundo, anchoMundo);
}

// Destructor.
Mundo::~Mundo(){}

//  Función que muestra la posición actual de la Hormiga y la malla del Mundo.
void Mundo::mostrarMundo() {
  int i = MallaMundo.Rows() - 1;
  cout << "La Hormiga se encuentra en la posición: " << mensajeHormiga.posY << "," << mensajeHormiga.posX << endl;
  while (i >= 0) {
    for (int j = 0; j < MallaMundo.Columns(); j++) {
      if (i == posicionHormiga.posY && j == posicionHormiga.posX) {
        cout << "|" << iconoHormiga;
      } else {
        cout << "|" << MallaMundo[i][j];
      }
    }
    cout << "|" << endl;
    cout << "--------------------\n";
    i--;
  }
}

// Función que retorna el nº de filas.
int Mundo::getNumFilas() {
  return numFilas;
}

// Función que retorna el nº de columnas.
int Mundo::getNumColumnas() {
  return numColumnas;
}

// Función que asinga el nuevo valor a celda indicada.
void Mundo::setValorCelda(int celdaY, int celdaX, char valor) {
  MallaMundo[celdaY][celdaX] = valor;
}

// Función que declara un nuevo objeto Mundo con los valores del usuario.
// Esto se debe a que el objeto MallaMundo está declarado en el .hpp, así que
// allí se crea con el constructor sin parámetros. 
// En esta función lo que hacemos es sobreescribirlo.
void Mundo::crearMundo(int altoMundo, int anchoMundo) {
  Matrix<char> MallaMundo2(altoMundo, anchoMundo, ' ');
  MallaMundo = MallaMundo2;
}

// Retorna el valor de la celda indicada.
char Mundo::getValorCelda(int valorY, int valorX) {
  return MallaMundo[valorY][valorX];
}

// Función que crea los bordes de la matriz. YA NO SE USA.
/*
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
*/

// Función que almacena en el objeto la nueva posición de la Hormiga.
void Mundo::setPosicionHormiga(int valorY, int valorX, char icono) {
  posicionHormiga = {valorY, valorX};
  iconoHormiga = icono;
}

// Función que actualiza la nueva posición de la Hormiga en la matriz.
void Mundo::actualizarPosicionHormiga(int valorY, int valorX) {
  mensajeHormiga = {mensajeHormiga.posY + valorY, mensajeHormiga.posX + valorX};
}

// Retorna la posición de la Hormiga.
Posicion Mundo::getPosicionHormiga() {
  return posicionHormiga;
}

// Función que expande la malla en la dirección indicada si la Hormiga avanza hacia algún límite.
void Mundo::expandirMalla(int direccion) {
  switch (direccion) {
  case 8:   // Norte
    MallaMundo.AddRowBack(1, ' ');
    numFilas++;
    break;
  case 9:   // Noreste
    MallaMundo.AddRowBack(1, ' ');
    numFilas++;
    MallaMundo.AddColumnBack(1, ' ');
    numColumnas++;
    break;
  case 6:   // Este
    MallaMundo.AddColumnBack(1, ' ');
    numColumnas++;
    break;
  case 3:   // Sureste
    MallaMundo.AddColumnBack(1, ' ');
    numColumnas++;
    MallaMundo.AddRowFront(1, ' ');
    numFilas++;
    break;
  case 2:   // Sur
    MallaMundo.AddRowFront(1, ' ');
    numFilas++;
    break;
  case 1:   // Suroeste
    MallaMundo.AddRowFront(1, ' ');
    numFilas++;
    MallaMundo.AddColumnFront(1, ' ');
    numColumnas++;
    break;
  case 4:   // Oeste
    MallaMundo.AddColumnFront(1, ' ');
    numColumnas++;
    break;
  case 7:   // Noroeste
    MallaMundo.AddColumnFront(1, ' ');
    numColumnas++;
    MallaMundo.AddRowBack(1, ' ');
    numFilas++;
    break;
  default:
    break;
  }
}

