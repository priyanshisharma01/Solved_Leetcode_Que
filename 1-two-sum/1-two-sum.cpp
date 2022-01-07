class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
          int i,j,a;
          for (i =0;i<nums.size();i++){
              a=target-nums[i];
              for (j=i+1;j<nums.size();j++){
                  if(nums[j]==a){
                   ans.push_back(i);
                    ans.push_back(j);
                   return ans;
                   }

              }

          }

return ans;
    }
};