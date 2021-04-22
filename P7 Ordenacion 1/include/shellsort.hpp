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
 * Archivo 'shellsort.cpp':
 * Archivo donde se encuentran la clase Shellsort.
*/

#include <iostream>
#include <vector>

using namespace std;

template<class Clave>
class Shellsort {
  private:

  public:
  Shellsort();
  ~Shellsort();

  void creacion(vector<Clave> vectorOrdenar);
  void printVector(vector<Clave> vector);
  void printVector(vector<Clave> vector, int pos1, int pos2);
  void printVector(vector<Clave> vector, int pos1, int pos2, int pos3);
  void deltasort(vector<Clave> &sec, int &delta, int &tamanoVector);
};
