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

/**
 * MODIFICACIÓN: usar un objeto DNI en vez de un entero.
*/


#include <iostream>
#include <string>
#include <vector>

#include <type_traits> // para is_same

#include "../include/insercion.hpp"
#include "../include/quicksort.hpp"
#include "../include/shellsort.hpp"
#include "../include/dni.hpp"

using namespace std;


template<class Clave>
void printVector(vector<Clave> vector) {
  for (int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}

/*
template<class Clave>
void printVector(vector<DNI> vector) {
  for (int i = 0; i < vector.size(); i++) {
    vector[i].print();
  }
}
*/

vector<int> generarNumeros(int tamanoVector) {
  vector<int> vectorOrdenar;
  int opcion;
  cout << "¿Quiere que sea aleatorio [1] o introducir los valores[2]?";
  cin >> opcion;
  int aux;
  while (vectorOrdenar.size() < tamanoVector) {
    if (opcion == 1) {
      aux = rand() % 1000 + 1;
    } else if (opcion == 2) {
      cin >> aux;
    }
    vectorOrdenar.push_back(aux);
  }
  return vectorOrdenar;
}


DNI generarDNIAleatorio() {
  int numAleatorio = rand() % 26;
  char tipo = 'a' + numAleatorio;
  int tamanoVector = 8;
  vector<int> numeros = generarNumeros(tamanoVector);
  numAleatorio = rand() % 26;
  char letra = 'a' + numAleatorio;
  DNI ejemplo(tipo, numeros, letra);
  return ejemplo;
}


template<class Clave>
void programa() {
  vector<Clave> vectorOrdenar; //= {10, 9, 82, 17, 22, 20, 21, 13, 2};
  vector<int> numeros;
  int tamanoVector, opcion = 0;
  cout << "Introduzca el tamaño del vector: ";
  cin >> tamanoVector;
  /*if constexpr (std::is_same<Clave, int>::value) { */
    numeros = generarNumeros(tamanoVector);
    for (int i = 0; i < numeros.size(); i++) {
      vectorOrdenar.push_back(numeros[i]);
    }
    /*
  } else if constexpr (std::is_same<Clave, DNI>::value) {
    int i = 0;
    while (i < tamanoVector) {
      vectorOrdenar.push_back(generarDNIAleatorio());
      i++;
    }
  }*/
  
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
  // Si llamamos al programa con <int> funciona correctamente:
  programa<int>();
  // Si llamamos al programa con <DNI> 
  //programa<DNI>();
}