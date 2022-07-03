class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        if(nums.size()<3)
        return res;    
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;    
            int lo=i+1;
            int hi=nums.size()-1;
            while(lo<hi)
            {
                
                if(nums[i]+nums[lo]+nums[hi]==0)
                {
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;
                    while(lo<hi && nums[lo]==nums[lo-1])
                    lo++;    
                }   
                else if(nums[i]+nums[lo]+nums[hi]>0)
                hi--;
                else
                lo++;    
            }    
        }  
        return res;
    }
};