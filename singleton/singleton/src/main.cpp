#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}
	Singleton(const Singleton &s) = delete;
	Singleton(const Singleton &&s) = delete;
	void operator=(const Singleton&) = delete;
	void operator=(const Singleton&&) = delete;
	void printHello() { cout << "Hello from Singleton!" << endl; }
private:
	Singleton() {}
};

int main() {
	Singleton&  s = Singleton::getInstance();
	s.printHello();
}