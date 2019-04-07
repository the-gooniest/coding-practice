#include <iostream>

using namespace std;

/* Note: # of 5's is always less than the number of 
 * 2's in the prime factoriztion of a factorial, so
 * we only need to count the number of 5's in the prime
 * factorization to get the number of trailing zeroes.
*/
int countTrailingZeros(int num) {
	int count = 0;
	for (int i = 5; i <= num; i *= 5)
		count += num / i;
	return count;
}

int main() {
	const int num = 100;
	cout << "Factorial: " << num  << "!" << endl;
	cout << "# of trailing zeros: " << countTrailingZeros(num) << endl;
}