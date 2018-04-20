#include <iostream>
#include <string>

using namespace std;


template <typename T>
class myvector {
private:
	int size;
	int capacity;
	int * p;
public:
	myvector() {
		int defaultsize = 8;
		this->p = new int[defaultsize];
		this->size = 0;
		this->capacity = 8;
	}
	void pushback(T val) {
		if (size < capacity) {
			p[size] = val;
			size++;
		}
		else {
			//开辟新的空间
			int * newp = new int[capacity * 2];
			for (int i = 0; i < capacity; i++) {
				newp[i] = p[i];
			}
			delete []p;
			p = newp;
			capacity = capacity * 2;
			
			//插入
			p[size] = val;
			size++;
		}
	}

	T operator[](int index) {
		if (index < size) {
			return p[index];
		}
	}
};


int main()
{
	myvector<int> vi;
	for (int i = 0; i < 8; i++) {
		vi.pushback(i);
	}

	for (int i = 0; i < 8; i++) {
		cout << vi[i]<< endl;
	}

	for (int i = 0; i < 16; i++) {
		vi.pushback(i);
	}

	return 0;
}