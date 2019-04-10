/*
Ivaylo Kirov
-- April 8, 2019 --
UC San Diego - Data Structures And Algorithms
Fibonacci Last Digit
*/

#include <iostream>
#include <map>

int get_fibonacci_last_digit_naive(int n) {
	if (n <= 1)
		return n;

	unsigned long long previous = 0;
	unsigned long long current = 1;
	std::map<int, int> cache;

	for (int i = 0; i < n; ++i) {
		unsigned long long tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % 10;
		cache[i + 2] = current;
	}

	return cache[n];
}

int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit_naive(n);
	std::cout << c << '\n';
}
