/*class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> ans(n,vector<int>(m,0));\
        for(int i=0;i<m;i++)
        {
            if(text1[0]==text2[i])
            {
                ans[0][i]=1;
            }
        
        }
        
        for(int j=0;j<n;j++)
        {
            if(text1[j]==text2[0])
            {
                ans[j][0]=1;
            }
        
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;i<m;j++)
            {
                if(text1[i]==text2[j])
                {
                    ans[i][j]=1+max(ans[i-1][j],max(ans[i-1][j-1],ans[i][j-1]));
                }
                else
                {
                    ans[i][j]=max(ans[i-1][j],max(ans[i-1][j-1],ans[i][j-1]));
                }
                
            }
        }
        return ans[n-1][m-1];
        
        
    }
};

*/


class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};