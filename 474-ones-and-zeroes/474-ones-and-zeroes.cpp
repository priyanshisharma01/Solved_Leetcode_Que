class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size(), j = 0;
        vector<pair<int, int>> zeros(len); //stores number of zeros and ones in each array element
        for(string str : strs) {
            int i = 0;
            for(char c : str) {
                if(c == '1')
                    i++;
            }
            zeros[j] = {i, str.size() - i};
            j++;
        };
        int dp[n + 1][m + 1][len + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int index = 1; index <= len; index++) {
                    if(i - zeros[index - 1].first >= 0 && j - zeros[index - 1].second >= 0) {
                        dp[i][j][index] = max(dp[i][j][index], dp[i - zeros[index - 1].first][j - zeros[index - 1].second][index - 1] + 1);
                    }
                    dp[i][j][index] = max(dp[i][j][index], dp[i][j][index - 1]);
                }
            }
        }
        
        return dp[n][m][len];
    }
};


/*#Method 1: Recursion + Memoization (top-down dp)

class Solution {
public:
    int dp[601][101][101];
    int fun(int i,int m, int n, vector<string> &s){
	   // base case
        if(i >= s.size() || n<0 || m<0 ){
            return 0;
        }
		// simply return the value if previously calculated
        if(dp[i][m][n] != -1)return dp[i][m][n];
        int c0 = count(s[i].begin(),s[i].end(),'0');
        int c1 = count(s[i].begin(),s[i].end(),'1');
		// if we can take this string , then ans_till_here = max(take it , avoid it)
        if(m-c0 >= 0 && n-c1 >= 0 )
        return dp[i][m][n] = max(fun(i+1,m-c0,n-c1,s)+1, fun(i+1,m,n,s));
		//otherwise avoid it
        else return dp[i][m][n] = fun(i+1,m,n,s);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,m,n,s);
    }
};
#Method 2: Tabulation(bottom-up dp)

class Solution {
public:
 
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int cnt[sz+1][2];
        for(int i=0;i<sz;i++){
            int c0 = count(s[i].begin(), s[i].end(),'0');
            int c1 = count(s[i].begin(), s[i].end(),'1');
            cnt[i+1][0]= c0;
            cnt[i+1][1]=c1;
        }
        for(int i=1;i <= sz;i++){
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    
                    if((j-cnt[i][0]) >=0 && (k-cnt[i][1]) >= 0){
                        dp[j][k] = max(dp[j][k], dp[j-cnt[i][0]][k-cnt[i][1]]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};*/