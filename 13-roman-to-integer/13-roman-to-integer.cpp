/*class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int add=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='I' ) 
            {
                add=add+1;
            }
            if(s[i]=='V' ) 
            {
                add=add+5;
            }
            if(s[i]=='X' ) 
            {
                add=add+10;
            }
            if(s[i]=='L' ) 
            {
                add=add+50;
            }
            if(s[i]=='C' ) 
            {
                add=add+100;
            }
            if(s[i]=='D' ) 
            {
                add=add+500;
            }
            if(s[i]=='M' ) 
            {
                add=add+1000;
            }
            
        }
        return add;
    }
};

*/

class Solution {
public:
    int romanToInt(string str) {
        
        int n = str.size();
        
        unordered_map<char, int> mp;
        
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50; mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000;
        
        int num = 0;
        
        for(int i = 0; i < n - 1; i++)
        {
            // if value of current character is less than the value of next character
            
            if(mp[str[i]] < mp[str[i + 1]])
            {
                num -= mp[str[i]];
            }
            else
            {
                num += mp[str[i]];
            }
        }
        
        // include the value of last character
        
        num += mp[str[n - 1]];
        
        return num;
    }
};
