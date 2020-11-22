
#include <iostream>

//#include <vector>
//#include "vector.hpp"

//#include "pila.hpp"

#include "dll_t.hpp"
#include "dll_node_t.hpp"

//#include "nodo.hpp"
//#include "lista.hpp"

//#include "cola.hpp"

using namespace std;

int main() {
/*
	vector_t<int> Vivi;
	Vivi.set_sz(3);
	cout << "Size de Vivi: " << Vivi.get_sz() << endl;
	Vivi.llenar();
	Vivi.add(9);
	cout << "Size de Vivi: " << Vivi.get_sz() << endl;
	Vivi.print();	

	pila_t<int> Pilotes;
	Pilotes.add(3);
	Pilotes.add(4);
	Pilotes.add(6);
	Pilotes.pop();
	cout << "\nElemento a la cabeza de la pila: " << Pilotes.get_head() << endl;
	
	cola_t<int> Scolly;
	Scolly.resize(3);
	Scolly.push(5);
	Scolly.push(3);	
	Scolly.push(1);
	Scolly.push(9);
	cout << "\nElemento al final de la cola: " << Scolly.get_tail() << endl;
*/
	dll_t<int> L1;
	dll_node_t<int> X = 4;
	L1.insert_head(X);
	X = 3;
	L1.insert_tail(X);
	L1.write(cout);
	


	//lista_t<int> Paco;
	//Paco.insert_head(5);
	//cout << Paco()->get_data() << endl;
	
	cout << "\nHi" << endl;
}
