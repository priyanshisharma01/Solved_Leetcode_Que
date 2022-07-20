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
                    color[graph[frontNode][i]] = -1*color[frontNode];
                    
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