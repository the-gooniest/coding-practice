#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

string& reverseString1(string& s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		char temp = s[i];
		int j = s.length() - i - 1;
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

string& reverseString2(string& s) {
	reverse(s.begin(), s.end());
	return s;
}

string& reverseString3(string& s) {
	char *c = &s[0];
	for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
		char temp = c[i];
		c[i] = c[j];
		c[j] = temp;
	}
	return s;
}

void reverseArrays(int size, char* left, char* right) {
	for (int i = 0, j = size - 1; i < j; i++, j--) {
		char temp = left[i];
		left[i] = right[j];
		right[j] = temp;
	}
}

string& reverseString4(string& s) {
	char *c = &s[0];
	const size_t bufSize = 256;
	const size_t length = s.length();
	const size_t halfLength = length / 2;
	char left[bufSize];
	char right[bufSize];
	for (int i = 0, j = length - bufSize; i < halfLength; i += bufSize, j -= bufSize) {
		memcpy(left, &c[i], bufSize);
		memcpy(right, &c[j], bufSize);
		reverseArrays(bufSize, left, right);
		memcpy(&c[i], left, bufSize);
		memcpy(&c[j], right, bufSize);
	}
	return s;
}

union Swapper {
	std::uint32_t n;
	std::uint16_t s[2];
	std::uint8_t c[4];

	inline void reverse() {
		Swapper dup(*this);
		c[0] = dup.c[3];
		c[1] = dup.c[2];
		c[2] = dup.c[1];
		c[3] = dup.c[0];
	}
};

string& reverseString5(string& s) {
	Swapper* start = (Swapper*)(&s[0]);
	const size_t size = sizeof(Swapper);
	const size_t length = s.length() / size;
	const size_t halfLength = length / 2;
	for (int i = 0, j = length - 1; i < halfLength; i++, j--) {
		Swapper left = start[i];
		Swapper right = start[j];
		left.reverse();
		right.reverse();
		start[i] = right;
		start[j] = left;
	}
	return s;
}

void reverseBytes(char* start, int size) {
	char *lo = start;
	char *hi = start + size - 1;
	char swap;
	while (lo < hi) {
		swap = *lo;
		*lo++ = *hi;
		*hi-- = swap;
	}
}

string& reverseString6(string& s) {
	char* start = &s[0];
	reverseBytes(start, s.length());
	return s;
}

template<class T>
T average(vector<T> times) {
	T sum = 0;
	for (T t : times)
		sum += t;
	return sum / times.size();
}

template<class T>
long long averageTime(int numTimes, T& input, T& (*func)(T&)) {
	vector<long long> times;
	for (int i = 0; i < numTimes; i++) {
		auto startTime = chrono::high_resolution_clock::now();
		func(input);
		auto endTime = chrono::high_resolution_clock::now();
		times.push_back(chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count());
	}
	return average(times);
}

int main() {
	const int size = 1024 * 1024;
	char * a = new char[size];
	uniform_int_distribution<int> dist(97, 122);
	default_random_engine gen;
	for (int i = 0; i < size; i++)
		a[i] = dist(gen);
	string input(a, size);
	const int numTimes = 5;
	vector<long long> times;
	// cout << input << endl;
	times.push_back(averageTime(numTimes, input, reverseString2));
	times.push_back(averageTime(numTimes, input, reverseString4));
	times.push_back(averageTime(numTimes, input, reverseString3));
	times.push_back(averageTime(numTimes, input, reverseString6));

	//times.push_back(averageTime(numTimes, input, reverseString3));
	// cout << input << endl;
	// times.push_back(averageTime(numTimes, input, reverseString3));
	for (auto time : times)
		cout << time << endl;
	//cout << endl << (double)times[1] / times[0] << endl;
	//cout << endl << (double)times[2] / times[0] << endl;
}