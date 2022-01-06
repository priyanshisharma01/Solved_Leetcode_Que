class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> uniq;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(uniq.find(nums[i]) == uniq.end()){
                uniq.insert(nums[i]);
                nums[j] = nums[i];
                j++;
            }
        }
        return uniq.size();
    }
};