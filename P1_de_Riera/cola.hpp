
#include <iostream> 
//#include <queue> 

using namespace std;

template<class T>
class cola_t {
	private:
		int size;
		T v_ [];
	public:
		cola_t();
		~cola_t();
		void resize(int sz);
		int get_size();
		T get_head();
		T get_tail();
		void push(T data);
};
