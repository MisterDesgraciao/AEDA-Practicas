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
/*  Constructor de Universo donde se encuentra el bucle.
*   Se desclara el objeto Mundo con sus parámetros de Nº Filas y Columnas.
*   Se declara un vector de Hormigas, por si más adelante se requieren varias.
*   Empieza el bucle de la creación, mostrándonos el Mundo en cada pasada
*   y donde la(s) Hormiga(s) comenzarán su camino.
*/
Universo::Universo(int iteraciones, int altoMundo, int anchoMundo) {
  Mundo MundoInsecto(altoMundo, anchoMundo);
  for (int iterador = 0; iterador < numHormigas; iterador++) {
    Hormiga Atomica(MundoInsecto, 4, 0);
    vectorHormigas.push_back(Atomica);
  }
  for (int i = 0; i < iteraciones; i++) {
    MundoInsecto.mostrarMundo();
    cout << "####################\n";
    for (int iteradorHormigas = 0; iteradorHormigas < numHormigas; iteradorHormigas++) {
      vectorHormigas[iteradorHormigas].reglasHormiga(MundoInsecto);
    }
  }
  MundoInsecto.mostrarMundo();
}

Universo::~Universo(){}
