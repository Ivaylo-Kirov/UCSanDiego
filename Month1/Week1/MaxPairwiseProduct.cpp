/*
Ivaylo Kirov
-- April 7, 2019 --
UC San Diego - Data Structures And Algorithms
Max Pairwise Product
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(std::vector<int>& numbers) {
	long long max_product = 0;
	int max = *std::max_element(std::begin(numbers), std::end(numbers));
	numbers.erase(std::find(std::begin(numbers), std::end(numbers), max));
	int n = numbers.size();

	for (int first = 0; first < n; ++first) {
		if ((long long)numbers[first] * max > max_product) max_product = (long long)numbers[first] * max;
	}

	return max_product;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct(numbers) << "\n";
	return 0;
}
