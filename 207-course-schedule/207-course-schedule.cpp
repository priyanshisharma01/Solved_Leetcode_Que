class Solution {
public:

bool isCycle(vector<int> g[], int i, vector<int> &vis) {
	if (vis[i] == 1) return true;
    if (vis[i] == 2) return false;
	if (vis[i] == 0) {
		vis[i] = 1;
		for (auto e : g[i]) {
			if (isCycle(g, e, vis)) return true;
		}
	}
	vis[i] = 2;
	return false;
}

bool canFinish(int n, vector<vector<int>>& prerequisites) {
	vector<int> g[n];
	for (auto e : prerequisites) {
		g[e[1]].push_back(e[0]);
	}
	vector<int> vis(n, 0);
	for (int i = 0; i < n; ++i) {
		if (isCycle(g, i, vis)) return false;
	}
	return true;
}
};