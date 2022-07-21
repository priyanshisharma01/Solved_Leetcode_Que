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
        if(vis[i]==0)
        {
            if (isCycle(g, i, vis)) return false;
        }
		
	}
	return true;
}
};




/*class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> in_degree(n, 0);
        vector<int> adj[n];
        
        for(auto p: prerequisites)
            adj[p[1]].push_back(p[0]);
        
        for(auto p: prerequisites)
            in_degree[p[0]]++;
        
        queue<int> q;
        
        // Implementing Kahn's algo
        for(int i = 0; i < n; ++i) {
            if(in_degree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto it: adj[node]) {
                if(in_degree[it] != 0)
                    in_degree[it]--;
                if(in_degree[it] == 0)
                    q.push(it);
            }
        }
        
        if(count == n)
            return true;
        
        return false;
        
    }
};*/