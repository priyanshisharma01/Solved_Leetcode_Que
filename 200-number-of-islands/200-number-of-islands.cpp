#include <queue>
/*
class Solution {
public:
    bool isvalid(int x,int y,int m,int n,vector<vector<char>>&grid)
    {
         return (x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]=='0' );
    }
    void bfs(vector<vector<char>>&grid,vector<vector<bool>>visited,int x,int y,int m,int n)
    {
        queue<pair<int,int>> q;
        visited[x][y]=1;
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, -1, 0, 1};
        pair<int,int> P(x,y);
        q.push(P);
        while(!q.empty())
        {
            pair front = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isvalid(front.first+dx[i],front.second+dy[i],m,n,grid))
                {
                    pair<int,int> L(front.first+dx[i],front.second+dy[i]);
                    q.push(L);

                }

            }
            
        }
        return;
        
    }
    int numIslands(vector<vector<char>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                      bfs(grid,visited,i,j,m,n);
                        count++;

                    
                    

                }
            }

        }
        return count;
    }
};
       
*/



class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    bool valid_index(int i, int j, vector<vector<char>>& grid) {
        return !(i<0 || j<0 || i>=grid.size() || j>=grid[0].size());
           
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j]='0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;
                int cj=DC[k]+j;
                if(!valid_index(ci, cj, grid))
                    continue;
                if(grid[ci][cj]=='1') {
                    q.push({ci, cj});
                    grid[ci][cj]='0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    no_of_islands++;
                    bfs(i, j, grid);
                }
            }
        }
        return no_of_islands;
    }
};
