
#include <iostream>

using namespace std;

template <class T>
class lista_t {
	private:
		nodo_t<T> head_;	//anterior dato
		nodo_t<T> tail_;	//próximo dato
		nodo_t<T> data_;
		int size;

		
	public:
		lista_t();	
		~lista_t();

		void merge(lista_t L1, lista_t L2);
		
		void insert_head(nodo_t nodo);
		void insert_tail(nodo_t nodo);
		void insert_data(nodo_t nodo);

		nodo_t<T> extract_head();
		nodo_t<T> extract_tail();
		
		nodo_t<T> get_head();
		nodo_t<T> get_tail();
		nodo_t<T> get_size();
		nodo_t<T> get_data();

		void remove(nodo_t<T> nodo);
};
