class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        vector<int> ans;
        if(nums.size()==1 && nums[0]==target)
        {
            ans.push_back(0);
             ans.push_back(0);
            return ans;
        }
        else if(nums.size()==1)
        {
            ans.push_back(-1);
             ans.push_back(-1);
            return ans;
        }
        if(i == j)
        {
            return ans;
        }
        bool flag =false;
        bool ifp=false;
        int idx;
        int jdx;
        bool jf=false;
        while(i<=j)
        {
           if(nums[i]==nums[j] && nums[i]==target)
           {
               ans.push_back(i);
               ans.push_back(j);
               return ans;
           }
            else if(nums[i]<target && nums[j]==target)
            {
                i++;
                flag=true;
                jf=true;
                jdx=j;
            }
            else if(nums[j]>target && nums[i]==target)
            {
                j--;
                flag=true;
                ifp=true;
                idx=i;
                
            }
            else
            {
                 i++;
                 j--;
                flag=false;
            }
            
        }
        if(flag==false)
        {
            ans.push_back(-1);
             ans.push_back(-1);
        }else if(ifp)
        {
             ans.push_back(idx);
             ans.push_back(idx);
        }
        else if(jf)
        {
             ans.push_back(jdx);
             ans.push_back(jdx);
        }
        return ans;
    }
};