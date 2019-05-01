/*
Ivaylo Kirov
-- April 30, 2019 --
UC San Diego - Data Structures And Algorithms
Graphs - Bellman Ford - Detect Negative Cycle
*/

#include <iostream>
#include <vector>
#include <map>
#include <limits>

using std::vector;

int negative_cycle(vector<vector<int>>& adj, vector<vector<int>>& cost) {
	//write your code here
	vector<long long> dist;
	dist.assign(adj.size(), std::numeric_limits<int>::max());
	dist[0] = 0;

	// adj[0][1].. dest
	// cost[0][1]. weight

	// iterate N - 1 times
	for (int i{}; i <= adj.size(); ++i) {
		// iterate through all edges
		for (int j{}; j < adj.size(); ++j) {
			for (int k{}; k < adj[j].size(); ++k) {
				long long destValue = adj[j][k];
				long long destWeight = cost[j][k];
				// relax
				if ((long long)dist[destValue] > (long long)dist[j] + (long long)destWeight) {
					// found a negative cycle
					if (i == adj.size()) return 1;
					dist[destValue] = (long long)dist[j] + (long long)destWeight;
				}
			}
		}

	}

	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cout << negative_cycle(adj, cost);
}
