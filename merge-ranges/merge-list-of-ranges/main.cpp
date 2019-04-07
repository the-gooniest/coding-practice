#include <algorithm>
#include <iostream>
#include <list>
#include <chrono>
#include <random>

using namespace std;

typedef pair<int, int> Range;

list<Range> mergeRanges(list<Range>& ranges) {
	if (ranges.size() == 0 || ranges.size() == 1) return ranges;
	ranges.sort();
	for (auto i = ++ranges.begin(); i != ranges.end();) {
		auto& left = *(prev(i));
		auto right = *i;
		if (right.first >= left.first && right.first <= left.second) {
			left.second = max(left.second, right.second);
			ranges.erase(i++);
		}
		else {
			i++;
		}
	}
	return ranges;
}


int main() {
	list<Range> ranges;
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