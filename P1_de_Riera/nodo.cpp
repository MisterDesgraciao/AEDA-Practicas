/*
Universidad de La Laguna. Algoritmos y Estructuras de Datos Avanzadas. 
2º Cuatrimestre. 2º Curso.

Listas enlazadas​ : La lista enlazada es una estructura de datos que nos permite almacenar
datos de una forma organizada, al igual que los vectores pero, a diferencia de estos, esta
estructura es dinámica, por lo que no tenemos que saber "a priori" los elementos que
puede contener. En una lista enlazada, cada elemento apunta al siguiente excepto el
último que no tiene sucesor.

Basado en el código de Jorge Riera Ledesma.

Hecho por Óscar Ignacio Pozo Fernández.
alu0101036526@ull.edu.es
*/
#include <iostream>
//#include <cassert>
//#pragma once

#include "nodo.hpp"

using namespace std;

//para poder separar el hpp y cpp necesito especificar el tipo T
template class nodo_t<int>;

template <class T>		//constructor por defecto
nodo_t<T>::nodo_t() {
	//data_ = NULL;
	next_ = NULL;
	prev_ = NULL;
}

template <class T>		//constructor con parámetro
nodo_t<T>::nodo_t(const T dato) {
	data_ = dato;
	next_ = NULL;
	prev_ = NULL;
}

template <class T>
nodo_t<T>::~nodo_t() {}

template <class T>
void nodo_t<T>::set_next(nodo_t prox) {
	next_ = prox;
}

template <class T>
void nodo_t<T>::set_prev(nodo_t anterior) {
	prev_ = anterior;
}

template <class T>
nodo_t<T> nodo_t<T>::get_next() {
	return next_;
}

template <class T>
nodo_t<T> nodo_t<T>::get_prev() {
	return prev_;
}

template <class T>
void nodo_t<T>::set_data(const T dato) {
	data_ = dato;
}

template <class T>
T nodo_t<T>::get_data() {
	return data_;
}
