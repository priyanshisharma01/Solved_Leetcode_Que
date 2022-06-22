class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();

            vector<int> prefix(n, 1);
            for (int i = 0; i < n - 1; i++)
            {
                prefix[i + 1] = nums[i] *prefix[i];
            }
           	// now we got the prefix array
           	// abhi mereko last se chalu karna hai ques
            int surfix = 1;
            
            for (int i = n - 1; i >= 0; i--)
            {
                prefix[i] *= surfix ;
                // surfix multiply hoga 
                surfix *= nums[i];
            }
            return prefix;
        }
};