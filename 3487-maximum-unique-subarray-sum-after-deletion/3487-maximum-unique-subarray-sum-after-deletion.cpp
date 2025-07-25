class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int temp = nums[0];
        bool firstTime = true;
        int ans = INT_MIN;
        int prev;
        for(int i=0; i<n; i++){
            if(nums[i]<0) temp = max(temp,nums[i]);

            if(nums[i]>=0 && firstTime){
                ans = nums[i];
                prev = nums[i];
                firstTime = false;
            }

            else if(nums[i]>0){
                if(prev == nums[i]) continue;
                else{
                    ans +=nums[i];
                    prev = nums[i];
                }
            }
        }

        if(ans==INT_MIN) return temp;
        return ans;
    }
};