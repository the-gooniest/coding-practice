#include <iostream>
#include <vector>

using namespace std;

vector<int> swap(vector<int> nums)
{
	int temp = nums[0];
	nums[0] = nums[1];
	nums[1] = temp;
	return nums;
}

vector<int> merge(vector<int> left, vector<int> right)
{
	int i = 0, j = 0;
	vector<int> output;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
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

vector<int> mergesort(vector<int> nums)
{
	if (nums.size() == 0 || nums.size() == 1)
		return nums;
	if (nums.size() == 2)
	{
		if (nums[0] > nums[1])
			return swap(nums);
	}
	int middleIndex = nums.size() / 2;
	vector<int> left(nums.begin(), nums.begin() + middleIndex);
	vector<int> right(nums.begin() + middleIndex, nums.end());
	left = mergesort(left);
	right = mergesort(right);
	return merge(left, right);
}

// Time complexity: O(nlogn) where n = # of vector elements
int main()
{
	vector<int> nums = { 1, 5, 7, 3, 9, 1, 0, -1, -3, 7, 4, 8 };
	nums = mergesort(nums);
	for (int num : nums)
		cout << num << " ";
}