#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

typedef pair<int, int> Range;

vector<Range> mergeRanges(vector<Range>& ranges) {
	if (ranges.size() == 0 || ranges.size() == 1) return ranges;
	sort(ranges.begin(), ranges.end());
	vector<Range> results;
	results.push_back(ranges[0]);
	for (int i = 1; i < ranges.size(); ++i) {
		auto& left = results.back();
		auto right = ranges[i];
		if (right.first >= left.first && right.first <= left.second) {
			left.second = max(left.second, right.second);
		}
		else {
			results.push_back(right);
		}
	}
	return results;
}


int main() {
	vector<Range> ranges;
	const int num = 10000;
	random_device dev;
	uniform_int_distribution<int> dist1(0, 10000);
	uniform_int_distribution<int> dist2(0, 10);
	default_random_engine gen(dev());
	for (int i = 0; i < num; ++i) {
		int first = dist1(gen);
		int second = first + dist2(gen);
		ranges.push_back(Range(first, second));
	}

	auto startTime = chrono::high_resolution_clock::now();
	ranges = mergeRanges(ranges);
	auto timeElapsed = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();

	cout << "Ranges" << endl;
	for (auto range : ranges)
		cout << range.first << " " << range.second << endl;
	cout << "\nTime elapsed: " << timeElapsed << endl;
}