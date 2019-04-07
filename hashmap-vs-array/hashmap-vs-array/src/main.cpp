#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <random>
#include <limits>
#include <numeric>

using namespace std;

struct Goob {
	int id;
	int data;
	Goob(int ID, int d) : id(ID), data(d) {}
};



int main() {
	random_device dev;
	default_random_engine eng(dev());
	uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
	vector<double> ratios;

	for (int i = 0; i < 100; ++i) {
		vector<int> v;
		vector<int> ids;
		unordered_map<int, int> m;
		const int nums = 2500;
		for (int i = 0; i < nums; i++) {
			int randId = dist(eng);
			int randData = dist(eng);
			v.push_back(randData);
			ids.push_back(randId);
			m.insert({ randId, randData });
		}

		auto startTime = chrono::high_resolution_clock::now();
		for (int i = 0; i < nums; ++i) {
			auto found = find(v.begin(), v.end(), v[i]);
		}
		auto endTime = chrono::high_resolution_clock::now();
		auto duration1 = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		// cout << "Vector: " << duration1 << endl;

		startTime = chrono::high_resolution_clock::now();
		for (auto id : ids) {
			auto found = m[id];
		}
		endTime = chrono::high_resolution_clock::now();
		auto duration2 = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		// cout << "Unordered Map: " << duration2 << endl;
		ratios.push_back((double)duration1 / duration2);
	}
	for (auto ratio : ratios)
		cout << ratio << endl;
	cout << "Ratio: " << accumulate(ratios.begin(), ratios.end(), 0.0) / ratios.size() << endl;
}