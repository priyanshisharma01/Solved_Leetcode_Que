class Solution {
public:
    bool canFinish(int numCourses , vector<vector<int>>& a) {
        //Topological Sort Concept
        // BFS
        int n=a.size();int ct=0;
        int in[numCourses ];//indegree of vertices
        
        for(int i=0;i<numCourses ;i++)in[i]=0;
        
        vector<int> adj[numCourses +1];
        queue<int> q;
        
        for(int i=0;i<a.size();i++) adj[a[i][1]].push_back(a[i][0]);//storing directed graph
        
        for(int i=0;i<n;i++)
        {
            in[a[i][0]]++;// calculating indegree
        }
        
        for(int i=0;i<numCourses ;i++)
        {
            if(in[i]==0) q.push(i); //if indegree==0, push in queue
        }
        
        while(q.empty()==false)
        {
            int z=q.front();
            
            for(auto x: adj[z])
            {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
           ct++; q.pop();
        }
        
        if(ct==numCourses )return true;
        else return false;
    }
};