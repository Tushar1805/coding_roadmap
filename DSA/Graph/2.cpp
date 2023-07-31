#include<iostream>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	// Code here
	vector<int> ans;
	queue<int> q;
	vector<bool> vis(V, false);

	q.push(0);
	vis[0] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		ans.push_back(curr);

		for (int neighbours : adj[curr]) {
			if (!vis[neighbours]) {
				vis[neighbours] = true;
				q.push(neighbours);
			}
		}
	}
	return ans;
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
	cout << "\nBFS Traversal: ";
	vector<int> ans = bfsOfGraph(n, adj);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
