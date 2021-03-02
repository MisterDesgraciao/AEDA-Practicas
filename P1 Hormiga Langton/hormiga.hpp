/* Universidad de La Laguna.
    Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

*/
#include <iostream>
#include <string>

#include "mundo.hpp"

using namespace std;

class Hormiga {
  private:
    int valorXinicial = 5;
    int valorYinicial = 5;
    char direccionActual = 'n';
  public:
    Hormiga();
    ~Hormiga();
    void reglasHormiga(Mundo &MundoInsecto);
};