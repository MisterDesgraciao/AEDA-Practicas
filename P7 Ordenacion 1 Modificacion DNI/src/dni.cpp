#include <iostream>
#include <vector>

#include "dni.hpp"

using namespace std;

DNI::DNI(char tipo, vector<int> numeros, char letra) {
  tipoDocumento = tipo;
  numero = numeros;
  letraDNI = letra;
}

DNI::~DNI() {}

char DNI::getTipo() {
  return tipoDocumento;
}

vector<int> DNI::getNumero() {
  return numero;
}

char DNI::getLetra() {
  return letraDNI;
}

void DNI::print() {
  cout << tipoDocumento;
  for (int i = 0; i < numero.size(); i++) {
    cout << numero[i];
  }
  cout << letraDNI << endl;
}