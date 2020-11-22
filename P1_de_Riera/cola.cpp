
#include <iostream> 
#include "cola.hpp"

using namespace std;


template <class T>
cola_t<T>::cola_t() {
	size = 5;
	cout << "Size de la cola por defecto: " << size << endl;
}

template <class T>
cola_t<T>::~cola_t() {}

template <class T>
void cola_t<T>::resize(int sz) {
	size = sz;
}

template <class T>
int cola_t<T>::get_size() {
	return size;
}

template <class T>
T cola_t<T>::get_head() {
	T aux = v_[0];
	return aux;
}

template <class T>
T cola_t<T>::get_tail() {
	return v_[size-1];
}

template <class T>
void cola_t<T>::push(T data) {
	for (int i=size-1; i>0; i--) {
		v_[i] = v_[i-1];
	} 
	v_[0] = data;
}


//para poder separar el hpp y cpp necesito especificar el tipo T
template class cola_t<int>;

