
#include <iostream>

using namespace std;

template <class T>
class nodo_t {
	private:
		nodo_t<T> next_;	//próximo dato
		nodo_t<T> prev_;	//anterior dato
		
		T data_;	//dato del elemento actual
		
	public:
		nodo_t();	//constructor con data = NULL
		nodo_t(const T dato);	//constructor con data = dato
		~nodo_t();
		
		void set_next(nodo_t prox);
		void set_prev(nodo_t anterior);
		
		nodo_t<T> get_next();
		nodo_t<T> get_prev();
		void set_data(const T dato);
		T get_data();
};
