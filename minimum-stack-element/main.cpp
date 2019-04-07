#include <iostream>
#include <stack>
#include <random>

using namespace std;

template<class T>
class MinStack {
	stack<T> s;
	T min;
public:
	bool empty() {
		return s.empty();
	}

	T getMin() {
		return min;
	}

	T& top() {
		T top = s.top();
		return (top < min) ? min : top;
	}

	void pop() {
		T top = s.top();
		s.pop();
		if (top < min)
			min = 2 * min - top;
	}

	void push(T elem) {
		if (s.empty()) {
			s.push(elem);
			min = elem;
			return;
		}
		if (elem >= min) {
			s.push(elem);
		}
		else {
			s.push(2 * elem - min);
			min = elem;
		}
	}
};

int main() {
	random_device dev;
	default_random_engine eng(dev());
	uniform_int_distribution<int> dist(0, 10);

	MinStack<int> s;
	for (int i = 0; i < 10; ++i) {
		int randomNum = dist(eng);
		s.push(randomNum);
		cout << s.top() << ", " << s.getMin() << endl;
	}
	cout << endl;

	while (!s.empty()) {
		cout << s.top() << ", " << s.getMin() << endl;
		s.pop();
	}

}