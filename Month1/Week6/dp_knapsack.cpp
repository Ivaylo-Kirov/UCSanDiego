/*
Ivaylo Kirov
-- April 16, 2019 --
UC San Diego - Data Structures And Algorithms
Dynamic P - Knapsack
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	//write your code here
	int capacity = W;
	int items = w.size();
	vector<vector<int>> matrix(items + 1, vector<int>(capacity + 1));

	for (int i = 1; i <= items; ++i) { // number of objects
		for (int j = 1; j <= capacity; ++j) { // capacity
			if (w[i - 1] <= j) { // if current object fits in the WEIGHT being processed
				int first = matrix[i - 1][j];
				int second = matrix[i - 1][j - w[i - 1]] + w[i - 1]; // 0 is usually the price
				matrix[i][j] = std::max(first, second);
			} else {
				// object doesn't fit - carry values over
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}

	return matrix[items][capacity];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	//int W = 10;
	//vector<int> w{ 1, 4, 8 };
	std::cout << optimal_weight(W, w) << '\n';
}
