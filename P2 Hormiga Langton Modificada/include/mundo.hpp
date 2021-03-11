/* Universidad de La Laguna.
  Algoritmos y Estructuras de Datos Avanzadas. Segundo curso.

  Práctica 2. La hormiga de Langton Modificada.
  La hormiga de Langton es un sistema discreto, determinista y muy simple. Esto es, dado un estado inicial en el paso de tiempo 0 se define el estado 
  en el paso de tiempo 1, y así sucesivamente. La versión clásica funciona sobre un «mundo» que es una malla cuadriculada bidimensional infinita, para esta versión modificada.

  Enunciado completo en: https://campusingenieriaytecnologia.ull.es/pluginfile.php/334688/mod_resource/content/15/AEDA-pract02.pdf

  Realizado por: Óscar Ignacio Pozo Fernández.
  Correo: alu0101036526@ull.edu.es

  Compilar con: g++ -std=c++17 -o MundoHormiga main.cpp universo.cpp hormiga.cpp mundo.cpp
  o 
  Makefile: make clean -> make.
*/
#include <iostream>
#include <string>
#include <vector>

#include "matrix.h"

using namespace std;

// Struct para acceder más fácil a las posiciones de la Hormiga.
struct Posicion {
  int posY;
  int posX;
};

class Mundo {
  private:
    int numFilas;
    int numColumnas;
    Matrix<char> MallaMundo;
    char iconoHormiga = '@';
    
  public:
    // struct que almacena con la posición de la Hormiga en la matriz acorde a lo simulado.
    struct Posicion posicionHormiga = {1,1};  
    // struct que almacena la posición de la Hormiga relativa al punto inicial.
    // Sirve de guía para el usuario para interpretar mejor la matriz.
    struct Posicion mensajeHormiga = {1,1};

    // Constructores
    Mundo();
    Mundo(int altoMundo, int anchoMundo);
    ~Mundo();

    void mostrarMundo();                            // Mostrar el contenido de la matriz
    void crearMundo(int altoMundo, int anchoMundo); // Crear un nuevo objeto Matrix<>
    //void crearBordes();

    int getNumFilas();    // Retorna el nº filas
    int getNumColumnas(); // Retorna el nº columnas

    void setValorCelda(int alto, int ancho, char valor);  // Otorga el valor concretado a la celda
    char getValorCelda(int valorY, int valorX);           // Retorna el valor de la celda

    void setPosicionHormiga(int valorY, int valorX, char icono);  // Concreta la nueva posición en la matriz
    void actualizarPosicionHormiga(int valorY, int valorX);       // Actualiza la posición de la Hormiga respecto al punto inicial. (Mensaje)
    Posicion getPosicionHormiga();                                // Retorna la posición de la Hormiga.

    void expandirMalla(int direccion1);   // Expandir la malla hacia la dirección indicada.
};