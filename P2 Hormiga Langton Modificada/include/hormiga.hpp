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

#include "mundo.hpp"

using namespace std;

class Hormiga {
  private:
    int valorY = 0;
    int valorX = 0;
    int direccionActual = 8;  // 8 = Norte
  public:
    // Constructores varios
    Hormiga(Mundo &MundoInsecto);
    Hormiga(Mundo &MundoInsecto, int valorY, int valorX);
    ~Hormiga();

    // Función que tiene las reglas de la Hormiga y actualiza su posición.
    void reglasHormiga(Mundo &MundoInsecto);
};