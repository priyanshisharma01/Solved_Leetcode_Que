class Solution {
public:
    void sortColors(vector<int>& nums) {
        map <int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int red = m[0];
        int white = m[1];
        int blue = m[2];
        
        for(int i = 0; i < nums.size(); i++){
            if(i < red)
                nums[i] = 0;
            else if(i >= red+white)
                nums[i] = 2;
            else
                nums[i] = 1;
        }
    }
};