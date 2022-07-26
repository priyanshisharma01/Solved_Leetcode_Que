class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        
        int result = nums[0];
        
        int topMax = nums[0];
        int topMin = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            int iMax = max(max((topMax * nums[i]), (topMin * nums[i])), nums[i]);
            int iMin = min(min((topMax * nums[i]), (topMin * nums[i])), nums[i]);
            
            
             topMax=iMax;
             topMin = iMin;
           
            
            result = max(result, topMax);
        }
        
        return result;
    }
};