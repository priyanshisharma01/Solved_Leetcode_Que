class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int remove = 0, n = intervals.size(), end=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=end)
                end = intervals[i][1];
            else
            {
                remove++;
                end = min(intervals[i][1],end);
            }
        }
        return remove;
    }
};