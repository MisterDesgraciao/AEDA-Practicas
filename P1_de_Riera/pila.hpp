

#include <iostream> 
#include <stack>

using namespace std;

template<class T>
class pila_t {
	private:
		stack<T> P1;
		
	public:
		pila_t();
		~pila_t();
		void add(T data);
		//void add(float number);
		//void add(char letra);
		int get_size();
		int get_head();
		void pop();	
		
};

/*
template<class T>
pila_t<T>::pila_t() {
}

template<class T>
pila_t<T>::~pila_t() {}

template<class T>
void pila_t<T>::add(T data){
	P1.push(data);
}	
*/
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
/*
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
}	*/
