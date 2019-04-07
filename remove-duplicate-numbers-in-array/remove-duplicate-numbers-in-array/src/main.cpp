#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void removeDuplicates(vector<int>& v) {
	sort(v.begin(), v.end());
	int lastIndex = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[lastIndex] != v[i]) v[++lastIndex] = v[i];
	}
	v.resize(lastIndex + 1);
}

// Time complexity: O(nlogn), n = size of vector
int main(int argc, char* argv[]) {
	stringstream s(argv[1]);
	vector<int> nums;
	int num;
	while (s >> num)
		nums.push_back(num);

	removeDuplicates(nums);
	for (int num : nums)
		cout << num << " ";
}