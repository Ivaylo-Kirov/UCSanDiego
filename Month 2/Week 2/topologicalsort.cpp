/*
Ivaylo Kirov
-- April 29, 2019 --
UC San Diego - Data Structures And Algorithms
Graphs - Topological Sort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using std::vector;

void dfs(vector<vector<int>>& adj, int current, vector<int>& results, std::unordered_set<int>& visited) {

	if (visited.find(current) == visited.end()) {
		visited.insert(current);
		for (int i{}; i < adj[current].size(); ++i) {
			if (visited.find(adj[current][i]) == visited.end()) {
				dfs(adj, adj[current][i], results, visited);
			}
		}

	}
	results.push_back(current);
}

vector<int> toposort(vector<vector<int>>& adj) {
	vector<int> results;
	std::unordered_set<int> visited;
	for (int i{}; i < adj.size(); ++i) {
		if (visited.find(i) == visited.end()) {
			dfs(adj, i, results, visited);
		}
	}

	std::reverse(results.begin(), results.end());
	return results;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	vector<int> order = toposort(adj);
	for (size_t i = 0; i < order.size(); i++) {
		std::cout << order[i] + 1 << " ";
	}
}
