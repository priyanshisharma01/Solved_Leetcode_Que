class Solution {
    public:
 bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> boxes(9,0);
        
        // fill rowwise
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    
                    int num = board[i][j]-'0';
                    int spos = i/3 * 3 + j/3;
                    // check if already filled
                    if((rows[i] & (1 << (num-1))) || (cols[j] & (1 << (num-1))) || (boxes[spos] & (1 << (num-1)))){
                        return false;
                    }
                    rows[i] = rows[i] ^ (1 << (num-1));
                    cols[j] = cols[j] ^ (1 << (num-1));
                 
                    boxes[spos] = boxes[spos] ^ (1 << (num-1));
                }
            }
        }
        
        return true;
        
        
        
        
        
        
        
    }
};