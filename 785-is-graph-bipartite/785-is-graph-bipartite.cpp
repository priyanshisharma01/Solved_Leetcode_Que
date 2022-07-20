class Solution 
{
public:
    bool helper(vector<vector<int>>&graph,vector<int>&colour,int curr)
    {
        for(auto it:graph[curr])
        {
            if(colour[it]==colour[curr])
            {
                return false;
            }
            else if(colour[it]==0)
            {
                colour[it]=-colour[curr];
                if(!helper(graph,colour,it))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int>colour(n,0);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==0) 
            {
                colour[i]=-1;
                if(!helper(graph,colour,i))
                    return false;
            }
        }
        return true;
    }
};
    /*
    bool dfs(vector<vector<int>>& graph,vector<int>color,int currnode,int currcolor)
    {
        bool ans=true;
        
        color[currnode]=currcolor;
        for(int i=0;i<graph[currnode].size();i++)
        {
            if(graph[currnode][i]==0)
            {
                color[graph[currnode][i]] = -1*color[currnode];
                 dfs(graph,color,graph[currnode][i],color[graph[currnode][i]] );
            }
            else if(color[graph[currnode][i]] == color[currnode]){
                    return false;}
                
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=true;
        int n=graph.size();
        vector<int> color(n,0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0)
            {
                 ans= (ans && dfs(graph,color,i,-1));
                if(ans==false)
                {
                    break;
                }
            }

        }
        return ans;
    }
};
*/


//bfs
/*
class Solution {
public:
    bool isBipartiteHelper(vector<vector<int>>& graph,vector<int>color,int currnode) {
        bool ans =true;
        
        queue<int> q;
        int currcolor=-1;
        q.push(currnode);
        color[currnode]= currcolor;
        while(!q.empty())
        {
            int frontNode = q.front();  
            for(int i = 0; i < graph[frontNode].size(); i++){
                
                if(color[graph[frontNode][i]] == 0){
                    
                    q.push(graph[frontNode][i]);
                    
                    
                }else if(color[graph[frontNode][i]] == color[frontNode]){
                    return false;
                }
                

            }
            q.pop();
            currcolor=-1*currcolor;

        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=true;
        int n=graph.size();
        vector<int> color(n,0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0)
            {
                 ans= (ans && isBipartiteHelper(graph,color,i));
                if(ans==false)
                {
                    break;
                }
            }

        }
        return ans;
    }
};
*/