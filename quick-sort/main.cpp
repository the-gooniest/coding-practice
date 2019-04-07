#include <iostream>

using namespace std;

void swap(int* a, int left, int right) {
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

int partition(int* a, int left, int right, int pivot) {
	while (left <= right) {
		while (a[left] < pivot) left++;
		while (a[right] > pivot) right--;
		if (left <= right) {
			swap(a, left, right);
			left++;
			right--;
		}
	}
	return left;
}

void quicksort(int* a, int left, int right) {
	if (left >= right) return;
	int pivot = a[(left + right) / 2];
	int index = partition(a, left, right, pivot);
	quicksort(a, left, index - 1);
	quicksort(a, index, right);
}

void quicksort(int *a, int size) {
	quicksort(a, 0, size - 1);
}

// Time complexity average case: O(nlogn)
// Time complexity worst case: O(n^n)
int main() {
	int nums[] = { 1, 5, 8, 3, 9, 0, 3 };
	quicksort(nums, sizeof(nums) / sizeof(int));
	for (int num : nums)
		cout << num << " ";
}