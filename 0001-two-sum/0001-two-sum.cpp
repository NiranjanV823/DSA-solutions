class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int,int> mp;

        for(int i=0; i<n; i++){
            int diff = target - nums[i];

            if(mp.find(diff)!=mp.end()){
                return {mp[diff],i};
            }

            else{
                mp[nums[i]]=i;
            }
        }
        return {0};
    }
};