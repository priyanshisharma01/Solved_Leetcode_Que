/*class Solution {
public:
        
bool searchMatrixHelper(vector<vector<int>>& matrix, int target , int i ,int j)
{
    int m = matrix.size();
        int n = matrix[i].size();
    if(matrix[i][j]==target)
        {
            return true;
        }
        
            while(i<m && j<n)
            {
                if(matrix[i][j]>target)
                {
                    bool ans1=searchMatrixHelper(matrix, target ,i-1,j);
                    bool ans2=searchMatrixHelper( matrix, target,i ,j-1);
                    if(ans1==false && ans2==false)
                    {
                        return false;
                    }
                    else{
                        return true;
                    }
                }
                else
                {
                    bool ans1=searchMatrixHelper(matrix, target ,i,j+1);
                    bool ans2=searchMatrixHelper( matrix, target,i+1,j);
                    if(ans1==false && ans2==false)
                    {
                        return false;
                    }
                    else{
                        return true;
                    }
                }
            }
        
        return false;
}
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=m/2;
        int j=n/2;
        return searchMatrixHelper(matrix,  target , i , j);
        
    }
};
*/

class Solution {
public:
    bool find(vector<vector<int>>& matrix, int target, int i, int j){
        if(i>=matrix.size() || i<0 || j>=matrix[0].size() || j<0){
            return false;
        }
        else{
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                return find(matrix, target, i+1,j);
            }
            else{
                return find(matrix,target,i,j-1);
            }
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find(matrix,target,0,matrix[0].size()-1);
    }
};