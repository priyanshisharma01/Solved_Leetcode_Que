//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        
        vector<vector<int>> ss;
        for(int i=0;i<n;i++)
        {
            vector<int> temp={end[i],start[i]};
            ss.push_back(temp);
        }
        sort(ss.begin(),ss.end());
        
        int s=ss[0][1];
        int e=ss[0][0];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(ss[i][1]>e)
            {
                ans++;
                s=ss[i][1];
                e=ss[i][0];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Endshttps://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan&id=level-1