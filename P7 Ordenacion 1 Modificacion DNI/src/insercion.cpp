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
 * Archivo 'insercion.cpp':
 * Archivo donde se encuentran la declaración formal de los métodos para el algoritmo
 * de Inserción.
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

#include "../include/insercion.hpp"
#include "../include/dni.hpp"

using namespace std;

template<class Clave>
Insercion<Clave>::Insercion() {
  //creacion();
}

template<class Clave>
Insercion<Clave>::~Insercion() {}

template<class Clave>
void Insercion<Clave>::creacion(std::vector<Clave> vectorOrdenar) {
  cout << "Ordenamos por Inserción." << endl;
  printVector(vectorOrdenar, -1);
  Clave valor;
  for (int pos = 1; pos < vectorOrdenar.size(); pos++) {
    valor = vectorOrdenar[pos];
    insertar(vectorOrdenar, pos, valor);
  }
  cout << "Vector ya ordenado: ";
  printVector(vectorOrdenar, vectorOrdenar.size());
}

template<class Clave>
void Insercion<Clave>::printVector(vector<Clave> vector, int posOrdenado) {
  for (int  i = 0; i <= posOrdenado; i++) {
    cout << GREEN << vector[i] << " " << RESET;
  }
  if (posOrdenado + 1 < vector.size()) {
    cout << RED << vector[posOrdenado + 1] << " " << RESET;
    if (posOrdenado + 2 < vector.size()) {
      for (int i = posOrdenado + 2; i < vector.size(); i++) {
        cout << vector[i] << " ";
      }
    }
  }
  cout << endl;
}

template<class Clave>
void Insercion<Clave>::insertar(vector<Clave> &sec, int &pos, int &valor) {
  int posicionIntroducir = 0;
  while (valor > sec[posicionIntroducir]) {
    posicionIntroducir++;
  }
  cout << "Introducir " << RED << valor << RESET << " en la posicion: " << posicionIntroducir << endl;
  int aux = sec[posicionIntroducir];
  for (int j = pos; j > posicionIntroducir; j--) {
    sec[j] = sec[j - 1];
  }
  sec[posicionIntroducir] = valor;
  unsigned int microsecond = 1000000;
  usleep(2 * microsecond);  //sleeps for 2 seconds
  printVector(sec, pos);
}

template class Insercion<int>;
//template class Insercion<DNI>;
