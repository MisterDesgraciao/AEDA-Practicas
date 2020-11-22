

#include <iostream>
//#include <vector>
#include "vector.hpp"

using namespace std;

//para poder separar el hpp y cpp necesito especificar el tipo T
template class vector_t<int>;

template<class T>
vector_t<T>::vector_t() {
	size = 0;
}

template<class T>
vector_t<T>::vector_t(int sz) {
	size = sz;
}

/*	//función que almacena otro vector??
template<typename T>
vector_t<T>::vector_t(const vector_t& v) {
	v_ = new T[size];
	for (int i=0; i<size; i++)
		v_[i] = v.v_[i];
}
*/

template<class T>
vector_t<T>::~vector_t() {}

template<class T>
int vector_t<T>::get_sz() {
	return size;
}

template<class T>
void vector_t<T>::set_sz(int sz) {
	size = sz;
}

template<class T>
void vector_t<T>::llenar() {
	T aux;
	cout << "Escriba los elementos para llenar el vector: " << endl;
	for (int i=0; i<size; i++) {
		cin >> aux;
		v_[i] = aux;
	}
}

template<class T>
void vector_t<T>::add(T data) {
	size++;
	v_[size-1] = data;
}

template<class T>
void vector_t<T>::insert(int pos, T data) {
	if (pos >= 0 && pos < size) {
		v_[pos] = data;
	}
}

template<class T>
void vector_t<T>::print() {
	for (int i=0; i<size; i++) {
		cout << v_[i];
	}
}

