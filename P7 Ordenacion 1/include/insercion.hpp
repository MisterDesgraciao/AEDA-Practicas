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
 * Archivo 'insercion.hpp':
 * Archivo donde se encuentran la clase Insercion
*/

#include <iostream>
#include <vector>

using namespace std;

class Insercion {
  private:

  public:
  Insercion(std::vector<int> vectorOrdenar);
  ~Insercion();

  void printVector(vector<int> vector, int posOrdenado);
  void insertar(vector<int> &sec, int &i, int &valor);
};
