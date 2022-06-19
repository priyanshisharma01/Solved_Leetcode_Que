class Solution {
public:
int majorityElement(vector<int>& nums) {
     int n=nums.size(); 
     unordered_map<int,int>m;
     for(auto x:nums)
        m[x]++;
       vector<pair<int,int>>v;
    int ans=0;
    for(auto x:m){
      v.push_back({x.second,x.first});
       }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i].first>n/2){
            ans+=v[i].second;
            break;
            }
    }
    
    return ans; 
}
};