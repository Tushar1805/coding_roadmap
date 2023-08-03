#include<bits/stdc++.h>
using namespace std;

class graph {
public:
	unordered_map<int, list<pair<int, int>>> adj;

	void addEdge(int u, int v, int weight) {
		pair<int, int> p = make_pair(v, weight);
		adj[u].push_back(p);
	}

	void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s) {
		visited[node] = true;
		for (auto i : adj[node]) {
			if (!visited[i.first]) {
				dfs(i.first, visited, s);
			}
		}
		s.push(node);
	}

	void getShortestPath(int src, vector<int> &dist, stack<int> &s) {
		dist[src] = 0;

		while (!s.empty()) {
			int t = s.top();
			s.pop();

			if (dist[t] != INT_MAX) {
				for (auto i : adj[t]) {
					if (dist[t] + i.second < dist[i.first]) {
						dist[i.first] = dist[t] + i.second;
					}
				}
			}
		}
	}

	void print() {
		for (auto i : adj) {
			cout << i.first << "->";
			for (auto j : i.second) {
				cout << "[" << j.first << ", " << j.second << "], ";
			}
			cout << endl;
		}
	}
};

int main() {
	graph g;
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 6);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	cout << "Adjacency list: " << endl;
	g.print();

	int N = 6;

	// Topological sort
	unordered_map<int, bool> visited;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			g.dfs(i, visited, s);
		}
	}

	// Getting distance of each node
	int src = 1;
	vector<int> dist(N);
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
	}
	g.getShortestPath(src, dist, s);

	cout << "\nShortest Distance: ";
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == INT_MAX)
			dist[i] = -1;
		else
			cout << dist[i] << " ";
	}
	return 0;
}