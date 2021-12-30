class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int count=0;
        int total=row*col;
        
        vector<int>ans;
        //index initializing
        int startingRow=0;
        int endingRow=row-1;
        int startingCol=0;
        int endingCol=col-1;
        
        while(count < total){
            //print starting row  --> startingCol to endingCol
            for(int index=startingCol; index<=endingCol && count < total; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;  
            }
            startingRow++; // going to the next row
            
            //print ending column --> startingRow to endingRow
            for(int index=startingRow; index<=endingRow && count < total; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--; // going to the previous column
            
            //print ending row --> endingCol to startingCol
            for(int index=endingCol; index>=startingCol && count < total; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--; // going to the previous row
                
            //print the starting column
            for(int index=endingRow; index>=startingRow && count < total; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;}
};



