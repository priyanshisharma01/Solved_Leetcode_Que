class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo=0;
        int hi=s.size()-1;
        char swap;
        
        while(lo<hi){
            swap=s[lo];
            s[lo] = s[hi];
            s[hi]=swap;
            lo++;
            hi--;
            
            
            
        }
    }
};