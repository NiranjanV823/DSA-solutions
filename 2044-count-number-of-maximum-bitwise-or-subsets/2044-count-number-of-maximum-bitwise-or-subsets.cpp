class Solution {
public:
    unordered_map<int,int> hash;
    void solve(int ind,vector<int>& nums, int ans){

        if(ind <0){
            hash[ans]++;
            return;
        }

        solve(ind-1,nums,ans);
        solve(ind-1,nums,nums[ind]|ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        hash.clear();
        solve(n-1,nums,0);

        int max_or =0 ;
        for(auto it:nums){
            max_or |= it;
        }

        return hash[max_or];
        
    }
};