class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=1;
        for(auto i:mp){
            if(ans<i.second){
                ans=i.second;
            }
        }
        int ans1=0;
         for(auto i:mp){
            if(i.second==ans){
                ans1+=ans;
            }
        }
            return ans1;
    }
};
