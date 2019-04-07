#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

template<class T>
bool partition(vector<T>& nums) {
	int sum = 0;
	sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0) {
		cout << "Sum is odd" << endl;
		return false;
	}

	auto half = sum / 2;
	auto size = nums.size();
	cout << half << ", " << size << endl;

	int** part = new int*[half + 1];
	for (int i = 0; i < half + 1; ++i)
		part[i] = new int[size + 1];

	for (size_t i = 0; i <= nums.size(); ++i)
		part[0][i] = true;

	for (auto i = 1; i <= sum / 2; ++i)
		part[i][0] = false;


	for (auto num : nums)
		cout << num << " ";
	cout << endl;
	for (auto i = 1; i <= sum / 2; ++i) {
		for (size_t j = 1; j <= nums.size(); ++j) {
			part[i][j] = part[i][j - 1];
			if (i >= nums[j - 1])
				part[i][j] = part[i][j] || part[i - nums[j - 1]][j - 1];
			cout << part[i][j] << " ";
		}
		cout << endl;
	}

	auto result = part[sum / 2][nums.size()];

	for (int i = 0; i < half + 1; ++i)
		delete[] part[i];
	delete[] part;

	return result;
}

int main() {
	vector<int> nums = { 19, 3, 15 };
	if (partition(nums))
		cout << "Nums can be paritioned" << endl;
	else
		cout << "Nums cannot be paritioned" << endl;
}