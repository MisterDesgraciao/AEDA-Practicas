/**
 * Universidad de La Laguna. Ingeniería Informática.
 * Algoritmos y Estructuras de Datos Avanzadas. 2º curso.
 * Práctica 7: Ordenación (1).
 * 
 * Implementar los algoritmos:
 *  -> Inserción.
 *  -> Quicksort.
 *  -> Shellsort.
 * 
 * Práctica realizada por: Óscar Ignacio Pozo Fernández
 * Correo: alu0101036526@ull.edu.es
 * 
 * Compilar con: make -> make clean
 * ó 
 * g++ -std=c++17 -o Ordena main.cpp insercion.cpp quicksort.cpp shellsort.cpp
 * 
 * Archivo 'quicksort.cpp':
 * Archivo donde se encuentran la clase Quicksort
*/

#include <iostream>
#include <vector>

using namespace std;

template<class Clave>
class Quicksort {
  private:

  public:
  Quicksort();
  ~Quicksort();

  void creacion(vector<Clave> vectorOrdenar);
  void printVector(vector<Clave> vector);
  void printVector(vector<Clave> vector, int pos1, int pos2);
  void AlgoritmoQuicksort(vector<Clave> &sec, int inicio, int final);
};
