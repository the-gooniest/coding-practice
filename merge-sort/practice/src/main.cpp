#include <iostream>
#include <vector>
#include <random>

using namespace std;

template<class T>
bool compare(T left, T right) {
	return left < right;
}

template<class T>
vector<T> swap(vector<T>& nums) {
	T temp = nums[0];
	nums[0] = nums[1];
	nums[1] = temp;
	return nums;
}

template<class T>
vector<T> merge(vector<T>& left, vector<T>& right) {
	int i = 0, j = 0;
	vector<T> output;
	while (i < left.size() && j < right.size()) {
		if (compare(left[i], right[j]))
			output.push_back(left[i++]);
		else
			output.push_back(right[j++]);
	}
	while (i < left.size())
		output.push_back(left[i++]);
	while (j < right.size())
		output.push_back(right[j++]);
	return output;
}

template<class T>
vector<T> mergeSort(vector<T> nums) {
	if (nums.size() <= 1) return nums;
	if (nums.size() == 2) {
		if (compare(nums[1], nums[0]))
			return swap(nums);
	}
	auto middle = nums.size() / 2;
	vector<T> left(nums.begin(), nums.begin() + middle);
	vector<T> right(nums.begin() + middle, nums.end());
	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

int main() {
	random_device dev;
	default_random_engine eng;
	uniform_int_distribution<int> dist(0, 100);

	vector<int> nums;
	for (int i = 0; i < 100; i++)
		nums.push_back(dist(eng));

	for (auto num : nums)
		cout << num << " ";
	cout << endl << endl;

	nums = mergeSort(nums);
	for (auto num : nums)
		cout << num << " ";
}