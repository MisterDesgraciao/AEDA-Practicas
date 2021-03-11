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

#include "../include/universo.hpp"

using namespace std;


int main() {
  // Los valores que recibe el constructor son: Nº de iteraciones, Nº de Filas, Nº de Columnas.
  Universo Tenerife(20, 5, 5);
}