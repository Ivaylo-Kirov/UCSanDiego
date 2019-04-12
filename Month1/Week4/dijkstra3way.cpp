/*
Ivaylo Kirov
-- April 12, 2019 --
UC San Diego - Data Structures And Algorithms
Dijkstra 3-way partioning
*/

#include <iostream>
#include <vector>

using std::vector;

struct Points {
	int lt{};
	int gt{};
};

Points partition3(vector<int> &a, int l, int r) {
	int pivot = a[l];
	int lt = l;
	int gt = r;
	int i = l;

	while (i <= gt) {
		if (a[i] < pivot) {
			std::swap(a[i++], a[lt++]);
			continue;
		}
		if (a[i] > pivot) {
			std::swap(a[i], a[gt--]);
			continue;
		}
		if (a[i] == pivot) {
			i++;
		}
	}

	return { lt, gt };
}

void randomized_quick_sort_3way(vector<int> &a, int l, int r) {
	if (l < r) {
		Points m = partition3(a, l, r);
		randomized_quick_sort_3way(a, l, m.lt - 1);
		randomized_quick_sort_3way(a, m.gt + 1, r);
	}
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	//vector<int> a{ 4, 3, 4, 9, 2 };
	randomized_quick_sort_3way(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
	std::cin.get();
}
