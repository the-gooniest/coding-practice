#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <stdio.h>
#include <vector>

#define DEFAULT_SIZE 16

template<class T>
class BinaryHeap {
public:
	BinaryHeap();
	~BinaryHeap();

	size_t parent(size_t i);
	size_t left(size_t i);
	size_t right(size_t i);
	size_t extractMin();
	T getMin();
	void decreaseKey(size_t i, T newValue);
	void deleteKey(T key);
	void insertKey(T key);
	void print();
	inline size_t capacity() { return _heap.capacity(); }
	inline size_t size() { return _heap.size(); }
private:
	std::vector<T> _heap;
};

template<class T>
BinaryHeap<T>::BinaryHeap() {}

template<class T>
BinaryHeap<T>::~BinaryHeap<T>() {}

template<class T>
inline size_t BinaryHeap<T>::parent(size_t i)
{

	return size_t();
}

template<class T>
size_t BinaryHeap<T>::left(size_t i)
{
	return size_t();
}

template<class T>
size_t BinaryHeap<T>::right(size_t i)
{
	return size_t();
}

template<class T>
size_t BinaryHeap<T>::extractMin()
{
	return _heap[0];
}

template<class T>
void BinaryHeap<T>::decreaseKey(size_t i, T newValue)
{
}

template<class T>
T BinaryHeap<T>::getMin()
{
	return T();
}

template<class T>
void BinaryHeap<T>::deleteKey(T key)
{
}

template<class T>
void BinaryHeap<T>::insertKey(T key)
{
	_heap.push_back(key);
}

template<class T>
void BinaryHeap<T>::print()
{
	printf("Heap: ");
	for (size_t i = 0; i < _heap.size(); i++)
		printf("%d, ", _heap[i]);
	printf("\n");
}

#endif
