

#include <iostream>
//#include <stack>
#include "pila.hpp"

using namespace std;


template<class T>
pila_t<T>::pila_t() {
}

template<class T>
pila_t<T>::~pila_t() {}

template<class T>
void pila_t<T>::add(T data){
	P1.push(data);
}	

/*
template<class T>
void pila_t<T>::add(float number){
	P1.push(number);
}

template<class T>
void pila_t<T>::add(char letra){
	P1.push(letra);
}
*/

template<class T>
int pila_t<T>::get_size() {
	return P1.size();
}

template<class T>
int pila_t<T>::get_head(){
	return P1.top();
}

template<class T>
void pila_t<T>::pop(){
	P1.pop();
}	

//para poder separar el hpp y cpp necesito especificar el tipo T
template class pila_t<int>;
