

#include <iostream> 
#include <vector>

using namespace std;

template<class T>
class vector_t {
	private:
		int size;
		T v_ [];
		//vector<T> myVector(size);
		
	public:
		vector_t();
		vector_t(int sz);
		~vector_t();
		int get_sz();
		void set_sz(int sz);
		void add(T data);
		void llenar();
		void insert(int pos, T data);
		void print();
};


