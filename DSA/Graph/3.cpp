#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, vector<int> adj[], vector<int> &component) {
	component.push_back(node);
	vis[node] = true;

	for (auto i : adj[node]) {
		if (!vis[i]) {
			dfs(i, vis, adj, component);
		}
	}
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {

	unordered_map<int, bool> vis;
	vector<int> component;

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i, vis, adj, component);
		}
	}
	return component;
}

int main() {
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	int m;
	cout << "Enter the number of edges: ";
	cin >> m;
	vector<int> adj[n];

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << "\nDFS Traversal: ";
	vector<int> ans = dfsOfGraph(n, adj);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
