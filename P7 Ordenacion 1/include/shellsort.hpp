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

class Shellsort {
  private:

  public:
  Shellsort(vector<int> vectorOrdenar);
  ~Shellsort();

  void printVector(vector<int> vector);
  void printVector(vector<int> vector, int pos1, int pos2);
  void printVector(vector<int> vector, int pos1, int pos2, int pos3);
  void deltasort(vector<int> &sec, int &delta, int &tamanoVector);
};
