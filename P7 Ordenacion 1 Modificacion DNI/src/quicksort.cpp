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
 * Archivo donde se encuentran la declaración formal de los métodos para el algoritmo
 * de Quicksort.
*/
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

#include <iostream>
#include <vector>
#include <unistd.h> //para usleep()
#include <type_traits> // para is_same

#include "../include/quicksort.hpp"
#include "../include/dni.hpp"

using namespace std;

template<class Clave>
Quicksort<Clave>::Quicksort() {}

template<class Clave>
Quicksort<Clave>::~Quicksort() {}

template<class Clave>
void Quicksort<Clave>::creacion(vector<Clave> vectorOrdenar) {
  cout << "Ordenamos por Quicksort: ";
  printVector(vectorOrdenar);
  AlgoritmoQuicksort(vectorOrdenar, 0, vectorOrdenar.size() - 1);
  cout << "Vector ya ordenado: ";
  printVector(vectorOrdenar);
}

template<class Clave>
void Quicksort<Clave>::printVector(vector<Clave> vector) {
  for (int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}

template<class Clave>
void Quicksort<Clave>::printVector(vector<Clave> vector, int pos1, int pos2) {
  for (int i = 0; i < vector.size(); i++) {
    if (i == pos1 || i == pos2) {
      cout << GREEN << vector[i] << RESET << " ";
    } else {
      cout << vector[i] << " ";
    }
  }
  cout << endl;
}

template<class Clave>
void Quicksort<Clave>::AlgoritmoQuicksort(vector<Clave> &sec, int inicio, int final) {
  int i = inicio;
  int f = final;
  int aux = 0;
  Clave pivote = sec[(final + inicio) / 2];
  cout << BLUE << "Pivote: " << pivote << RESET << endl;
  while (i <= f) {
    while (sec[i] < pivote) {
      i++;
    };
    while (sec[f] > pivote) {
      f--;
    };
    if (i <= f) {
      if (i != f) {
        printVector(sec, i, f);
        cout << "Intercambiamos: " << GREEN <<  sec[i] << " y " << sec[f] << RESET << endl;
        unsigned int microsecond = 1000000;
        usleep(2 * microsecond);  //sleeps for 2 seconds
        aux = sec[i];
        sec[i] = sec[f];
        sec[f] = aux;
      }
      i++;
      f--;
    }
  }
  //printVector(sec);
  if (inicio < f) {
    AlgoritmoQuicksort(sec, inicio, f);
  }
  if (i < final) {
    AlgoritmoQuicksort(sec, i, final);
  }
}

template class Quicksort<int>;
//template class Quicksort<DNI>;