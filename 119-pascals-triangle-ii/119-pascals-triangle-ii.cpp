class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        int val = 1;
        long factor = 1;
        
        
        vector<int> r;
        
        
    
        
          for(int j = 0; j <= rowIndex; j++) {
            r.push_back(val);
            factor = factor * (rowIndex-j);
            factor = factor / (j+1);
            val = (int) factor;
        }
        return r;
    
}
};
    