class Solution {
public:
    /*
    string addStrings(string num1, string num2) {
        string ans="";
        int n=num1.length();
        int m=num2.length();
        int carry=0;
        if(n>m)
        {
            while(m!=0){
            int l=num1[n-1]+num2[n-1]+carry;
                int p=l%10;
            ans=ans+"'p'-'0'";
            int carry = l/10;
            m--;
            n--;}
            while(n!=0)
            {
                int w=num1[n-1]+carry;
                ans=ans+"w%10";
                int carry = w/10;
                n--;
                
            }
            
        }
        else{
            while(n!=0){
            int l=num1[m-1]+num2[m-1]+carry;
                int r=l%10;
            ans=ans+"'r'-'0'";
            int carry = l/10;
            n--;
            m--;}
            while(m!=0)
            {
                int w=num1[m-1]+carry;
                ans=ans+"w%10";
                int carry = w/10;
                m--;
                
            }

         }

        reverse_str(ans);
        return ans;
    }
};
*/
string addStrings(string num1, string num2) {
        
        string res;
        int sum = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        
        while(i >= 0 && j >= 0)
        {
            sum += (num1[i--] - '0') + (num2[j--] - '0');
            res.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        while(i >= 0)
        {
            sum += (num1[i--] - '0');
            res.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        while(j >= 0)
        {
            sum += (num2[j--] - '0');
            res.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        if(sum > 0)
            res.push_back(char(sum%10 + '0'));
        reverse(res.begin(), res.end());
        
        return res;
    }
};
