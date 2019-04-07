#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int binarySearch(int* a, int left, int right, int num) {
	while (left <= right) {
		int middle = left + (right - left) / 2;
		int found = a[middle];
		if (found == num)
			return middle;
		else if (found < num)
			left = middle + 1;
		else
			right = middle - 1;
		cout << left << " " << right << endl;
	}
	return -1;
}

// We don't check the bounds on a because a is "infinite"
// for the sake of this problem
int searchArray(int* a, int num) {
	int left = 0;
	int right = 1;
	while (a[right] < num) {
		left = right;
		right *= 2;
	}
	cout << "right index: " << right << endl;
	return binarySearch(a, left, right, num);
}

int main() {
	random_device d;
	default_random_engine eng(d());
	uniform_int_distribution<int> dist(0, 1000);

	vector<int> nums(1000);
	for (int i = 0; i < nums.size(); ++i)
		nums[i] = dist(eng);

	sort(nums.begin(), nums.end());

	const int numToFind = 200;
	int index = searchArray(&nums[0], numToFind);
	cout << "Num to find: " << numToFind << endl;
	cout << "Index found: " << index << endl;
	if (index != -1)
		cout << nums[index] << endl;

}