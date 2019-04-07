#include <iostream>
#include <string>

using namespace std;

template<class T>
bool compare(T left, T right) {
	return left < right;
}

template<class T>
void swap(T* a, int left, int right) {
	T temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

template<class T>
int partition(T* a, int left, int right, T pivot) {
	while (left <= right) {
		while (compare(a[left], pivot))
			left++;
		while (compare(pivot, a[right]))
			right--;
		if (left <= right) {
			swap(a, left, right);
			left++;
			right--;
		}
	}
	return left;
}

template<class T>
void quicksort(T* a, int left, int right) {
	if (left >= right) return;
	T pivot = a[(left + right) / 2];
	int index = partition(a, left, right, pivot);
	quicksort(a, left, index - 1);
	quicksort(a, index, right);
}

template<class T>
void quicksort(T* a, int size) {
	quicksort(a, 0, size - 1);
}

int main() {
	string elems[] = { "abc", "def", "afe", "ebv", "ggg", "zzz", "aaa", "bbb" };
	quicksort(elems, sizeof(elems) / sizeof(elems[0]));
	for (auto elm : elems)
		cout << elm << " ";
}