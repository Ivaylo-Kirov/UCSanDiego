/*
Ivaylo Kirov
-- April 10, 2019 --
UC San Diego - Data Structures And Algorithms
Greedy - Fractional Knapsack
*/

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values) {
	double value = 0.0;

	std::priority_queue<std::pair<double, int>> store;

	for (int i{}; i < values.size(); ++i) {
		double ratio = (double)values[i] / (double)weights[i];
		store.push(std::make_pair(ratio, i));
	}
	double filled_capacity{};

	// write your code here
	while (filled_capacity < capacity) {
		double rem_capacity = (double)(capacity - filled_capacity);

		// first = ratio | second = index
		int index = store.top().second;

		// fill as much as you can from the highest ratio item
		if (rem_capacity >= weights[index]) {
			value += values[index];
			filled_capacity += weights[index];
		} else {
			// =========================================
			// WALKTHROUGH AGAIN AND ADJUST REMAINING CAPACITY
			// =========================================
			value += (double)values[index] / (double)weights[index] * rem_capacity;
			filled_capacity += weights[index];
		}

		// remove item after use
		store.pop();

		// check if we ran out of items
		if (store.empty()) break;
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	std::vector<int> values(n);
	std::vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);
	//double optimal_value = get_optimal_value(50, { 20, 50, 30 }, { 60, 100, 120 });

	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	std::cout << optimal_value << std::endl;
	return 0;
}
