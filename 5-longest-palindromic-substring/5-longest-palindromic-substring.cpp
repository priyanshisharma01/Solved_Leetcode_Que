class Solution {
public:
    string longestPalindrome(string &s) {
        int ansl=0;
        int ansr=0;
        int left=0;
        int right=0;
        for(int j=0;j<s.length();j++){

            if(2*(s.length()-j)-1<=ansr-ansl+1){
                continue;
            }
            left=j-1;
            right=j+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                
                left--;
                right++;
                
            }
            if(right-left-1>=ansr-ansl+1){
               
                ansl=left+1;
                ansr=right-1;  
           }
        }
         for(int j=0;j<s.length();j++){

             if(2*(s.length()-j)<=ansr-ansl+1){
                continue;
            }
             left=j;
            right=j+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                
                left--;
                right++;
                
            }
            if(right-left-1>ansr-ansl+1){
               
                ansl=left+1;
                ansr=right-1;  
           }
        }
        string ans="";
        for(int i=ansl;i<=ansr;i++)
            ans+=s[i];
        return ans;
    }
};
