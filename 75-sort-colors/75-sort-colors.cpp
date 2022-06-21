class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> r;
        vector<int> w;
        vector<int> b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                r.push_back(nums[i]);
            }
             else if(nums[i]==1)
            {
                w.push_back(nums[i]);
            }
            else
            {
                b.push_back(nums[i]);
            }
        }
        r.insert(r.end(),w.begin(),w.end());
        r.insert(r.end(),b.begin(),b.end());
        nums =r;
        return;
    }
};