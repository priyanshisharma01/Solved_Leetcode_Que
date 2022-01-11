class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> map;
       int count=ransomNote.size();
       for(char c:magazine)
           map[c]++;
       for(char c1:ransomNote){
            if(map[c1] && map[c1]>0){
                map[c1]--;
                count--;
            }      
        }
        if(count)
            return false;
        else
            return true;
    }
};