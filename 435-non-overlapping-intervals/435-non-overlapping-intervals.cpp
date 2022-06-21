/*#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count =0;
        unordered_map<int,int> mp;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++)
        {
        if(intervals[i][1]!=intervals[i+1][0])
        {
            count++;
            intervals.erase(intervals.begin()+i);
        }
    }
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][0]]++;
        }
        auto iter = mp.begin();
    while (iter != mp.end()) {
        if(iter->second >1)
        {
            for(int j=1;j<iter->second;j++)
            {
                count++;
            }
           
        }
        ++iter;
    }
    
        return count;
    }
};
*/


bool mycmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
class Solution {
  
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if (intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end(),mycmp);
        int prevend=intervals[0][1];
        int count=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<prevend)count++;
            else{
                prevend=intervals[i][1];
            }
        }
        return count;
    }
};