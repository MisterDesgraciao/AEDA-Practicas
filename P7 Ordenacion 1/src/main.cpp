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
 * Archivo 'main.cpp':
 * Archivo principal donde se encuentra el menú donde elegir el algoritmo y generar el vector.
*/

#include <iostream>
#include <vector>

#include "../include/insercion.hpp"
#include "../include/quicksort.hpp"
#include "../include/shellsort.hpp"

using namespace std;

void printVector(vector<int> vector) {
  for (int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}

template<class Clave>
void programa() {
  vector<Clave> vectorOrdenar; //= {10, 9, 82, 17, 22, 20, 21, 13, 2};
  int tamanoVector, opcion = 0;
  cout << "Introduzca el tamaño del vector: ";
  cin >> tamanoVector;
  cout << "¿Quiere que sea aleatorio [1] o introducir los valores[2]?";
  cin >> opcion;
  Clave aux;
  while (vectorOrdenar.size() < tamanoVector) {
    if (opcion == 1) {
      aux = rand() % 1000 + 1;
    } else if (opcion == 2) {
      cin >> aux;
    }
    vectorOrdenar.push_back(aux);
  }
  cout << "El vector a ordenar es: ";
  printVector(vectorOrdenar);
  int eleccion = 0;
  cout << "Elija el algoritmo a usar para ordenar el vector:\n1.Inserción.\n2.Quicksort.\n3.Shellsort." << endl;
  cin >> eleccion;
  if (eleccion == 1) {
    Insercion<Clave> algoritmo;
    algoritmo.creacion(vectorOrdenar);
  } else if (eleccion == 2) {
    Quicksort<Clave> algoritmo;
    algoritmo.creacion(vectorOrdenar);
  } else if (eleccion == 3) {
    Shellsort<Clave> algoritmo;
    algoritmo.creacion(vectorOrdenar);
  } else {
    cout << "Opción no soportada." << endl;
  }
}

int main() {
  programa<int>();
}