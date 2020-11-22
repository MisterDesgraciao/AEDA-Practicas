

#include <iostream>
#include <cassert>
#include <cstdio>

#include "lista.hpp"
#include "nodo.hpp"

using namespace std;

template <class T>
lista_t<T>::lista_t() {}

template <class T>
lista_t<T>::~lista_t() {}

//para poder separar el hpp y cpp necesito especificar el tipo T
template class lista_t<int>;

/*
void ordenar(lista_t AUX) {
	int menor;
	for (int i=0; i<size; i++) {
		AUX
	}
	
}
*/

//MODIFICACIÓN: Recibir dos listas enlazadas ya ordenadas y hacer un merge ordenado
// que genere una tercera lista.
template <class T>
void lista_t<T>::merge(lista_t L1, lista_t L2) {
	//suponemos las dos listas L1 y L2 como ordenadas
	lista_t<T> aux;
	int menor = 1000;
	string L1N;
	string L2N;

	for (int i=0; i<size*2; i++) {
		if( L1.L1Nget_data() <= L2.L2Nget_data() ) {
			aux.insert_tail( L1.L1Nget_data() );
			L1N = L1N + "get_next()->";
		}else{
			aux.insert_tail( L2.L2Nget_data() );
			L2N = L2N + "get_next()->";
		}
	}
	
}

template <class T>
lista_t<T>::insert_head(nodo_t nodo) {
	if ( !empty() ) {
		head_->set_prev(nodo);  //el nodo se convierte en anterior a head
		nodo->set_next(head_);  //el próximo del nodo es head
		head_ = nodo;
	}else{
		head_ = nodo;
		tail_ = head_;
	}
	size++;
}

template <class T>
lista_t<T>::insert_tail(nodo_t nodo) {
	if ( empty() ) {
		head_ = nodo;
		tail_ = head_;
	}else{
		tail_->set_next(nodo);
		nodo->set_prev(tail_);
		tail_ = nodo;
	}
}

template <class T>
lista_t<T>::insert_data(T valor) {
	data_->set_data(valor);
}

template <class T>
nodo_t<T> lista_t<T>::extract_head() {
	assert( !empty() );

	nodo_t<T>* aux = head_;
	head_ = head_->get_next();
	if (head_)
		head_->set_prev(NULL);
	else
		tail_ = NULL;
	
	size--;
	aux->set_next(NULL);
	aux->set_prev(NULL);
	return aux;	
}

template <class T>
nodo_t<T> lista_t<T>::extract_tail() {
	assert( !empty() );

	nodo_t<T>* aux = tail_;
	tail_ = tail_->get_prev();
	if (tail_ != NULL) {
		tail_->set_next(NULL);
	}else{
		head_ = NULL;
	}
	
	size--;
	aux->set_next(NULL);
	aux->set_prev(NULL);
	return aux;	
}

template <class T>
nodo_t<T> lista_t<T>::get_head() {
	return head_;
}

template <class T>
nodo_t<T> lista_t<T>::get_tail() {
	return tail_;
}

template <class T>
nodo_t<T> lista_t<T>::get_size() {
	return size;
}

template <class T>
nodo_t<T> lista_t<T>::get_data() {
	return data_->get_data();
}

template <class T>
void lista_t<T>::remove(nodo_t nodo) {
	assert(nodo != NULL);
	
	if (nodo->get_prev() != NULL) 
		nodo->get_prev()->set_next( nodo->get_next() );
	else
		head_ = nodo->get_next();
	
	if (nodo->get_next() != NULL)
		nodo->get_next()->set_prev( nodo->get_prev() );
	else
		tail_ = nodo->get_prev();

	delete nodo;
	size--;
}
