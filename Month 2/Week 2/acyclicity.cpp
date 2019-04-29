/*
Ivaylo Kirov
-- April 28, 2019 --
UC San Diego - Data Structures And Algorithms
Graphs - Acyclicity
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using std::vector;
using std::pair;

bool acyclicUtil(int current, vector<vector<int>>& adj) {

	static std::unordered_set<int> visited;
	static std::unordered_set<int> processing;

	if (visited.find(current) == visited.end()) {
		visited.insert(current);
		processing.insert(current);

		for (int j{}; j < adj[current].size(); ++j) {
			// if not already visited, recurse
			if (visited.find(adj[current][j]) == visited.end() && acyclicUtil(adj[current][j], adj)) {
				return true;
			// otherwise, if already visited, check if it's being processed
			} else if (processing.find(adj[current][j]) != processing.end()) {
				return true;
			}
			// basically, while you're DFSing a Vertex, if any node can reach that Vertex, then you have a cycle
		}

	}

	processing.erase(current);
	return false;
}

int acyclic(vector<vector<int>> &adj) {
	//write your code here
	for (int i = 0; i < adj.size(); i++) {
		if (acyclicUtil(i, adj)) {
			return true;
		}
	}

	return false;

}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	std::cout << acyclic(adj);
}
