/* Universidad de La Laguna.
    Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

*/
#include <iostream>
#include <string>

using namespace std;

struct Posicion {
  int posY;
  int posX;
};


class Mundo {
  private:

    int numFilas = 10;
    int numColumnas = 10;
    char celdasMundo[10][10];
    char iconoHormiga = '@';
    
  public:
    struct Posicion posicionHormiga = {1,1};   //usar este struct genera un stack smashing

    Mundo();
    Mundo(int altoMundo, int anchoMundo);
    ~Mundo();
    void mostrarMundo();
    void crearMundo();
    void crearBordes();

    int getNumFilas();
    int getNumColumnas();

    void setValorCelda(int alto, int ancho, char valor);
    char getValorCelda(int valorY, int valorX);

    void setPosicionHormiga(int valorY, int valorX, char icono);
    Posicion getPosicionHormiga();
};