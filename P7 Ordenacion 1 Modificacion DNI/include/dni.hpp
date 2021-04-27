#include <iostream>
#include <vector>

using namespace std;

class DNI {
  private:
    char tipoDocumento;
    vector<int> numero;
    char letraDNI;

  public:
    DNI(char tipo, vector<int> numeros, char letra);
    ~DNI();

    char getTipo();
    vector<int> getNumero();
    char getLetra();
    void print();
};
