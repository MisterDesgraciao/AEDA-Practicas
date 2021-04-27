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
 * Archivo donde se encuentran la declaración formal de los métodos para el algoritmo
 * de Shellsort.
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

#include "../include/shellsort.hpp"
#include "../include/dni.hpp"

using namespace std;

template<class Clave>
Shellsort<Clave>::Shellsort() {}

template<class Clave>
Shellsort<Clave>::~Shellsort() {}

template<class Clave>
void Shellsort<Clave>::creacion(vector<Clave> vectorOrdenar) {
  float alfa = 0;
  cout << "Valor de Alfa (constante de reducción): [Valor entre 0 y 1]" << endl;
  cin >> alfa;
  if (alfa > 1 || alfa < 0) {
    cerr << "El valor de alfa debe estar entre 0 y 1: 0 < alfa < 1." << endl;
    exit(1);
  }
  int tamanoVector = vectorOrdenar.size();
  int delta = tamanoVector;
  while (delta > 1) {
    delta = delta * alfa;
    deltasort(vectorOrdenar, delta, tamanoVector);
  }
  cout << "Vector ya ordenado: ";
  printVector(vectorOrdenar);
}

template<class Clave>
void Shellsort<Clave>::printVector(vector<Clave> vector) {
  for (int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}

template<class Clave>
void Shellsort<Clave>::printVector(vector<Clave> vector, int pos1, int pos2) {
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
void Shellsort<Clave>::printVector(vector<Clave> vector, int pos1, int pos2, int pos3) {
  for (int i = 0; i < vector.size(); i++) {
    if (i == pos1 || i == pos2 || i == pos3) {
      cout << GREEN << vector[i] << RESET << " ";
    } else {
      cout << vector[i] << " ";
    }
  }
  cout << endl;
}

template<class Clave>
void Shellsort<Clave>::deltasort(vector<Clave> &sec, int &delta, int &tamanoVector) {
  Clave aux; 
  int j = 0;
  for (int i = delta; i < tamanoVector; i++) {
    //printVector(sec);
    aux = sec[i];
    j = i;
    while ((j >= delta) && (aux < sec[j - delta])) {
      sec[j] = sec[j - delta];
      j = j - delta;
      
    }
    sec[j] = aux;
    printVector(sec, i, j);
    unsigned int microsecond = 1000000;
    usleep(2 * microsecond);  //sleeps for 2 seconds
  }
}

template class Shellsort<int>;
//template class Shellsort<DNI>;