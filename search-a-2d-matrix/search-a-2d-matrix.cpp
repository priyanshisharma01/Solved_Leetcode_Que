class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool search = false;
        
        int x = 0;
        int y = n-1;
        
        while(x < m && y < n && x > -1 && y > -1) {
            if(matrix[x][y] == target) {
                search = true;
                break;
            }
            
            else if(matrix[x][y] > target) {
                y--;
            }
            
            else {
                x++;
            }
        }
        
        return search;
    }
};