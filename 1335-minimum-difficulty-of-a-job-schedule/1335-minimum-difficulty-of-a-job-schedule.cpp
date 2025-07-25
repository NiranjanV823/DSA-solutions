class Solution {
public:
    // Use a 2D DP table to store results: dp[ind][day]
    // Initialize with -1 to indicate uncomputed states
    vector<vector<int>> dp;

    int solve(int ind, int day, vector<int>& nums){
        // Base Case for day == 1
        if(day == 1){
            int maxi = INT_MIN;
            for(int i = ind; i < nums.size(); i++){
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        // Check if the result is already computed
        if(dp[ind][day] != -1) {
            return dp[ind][day];
        }

        int maxi = INT_MIN;
        int ans = INT_MAX;

        // The loop condition ensures there are enough jobs left for remaining days
        // (nums.size() - i) >= day - 1  => i <= nums.size() - day
        for(int i = ind; i <= nums.size() - day; i++){
            maxi = max(maxi, nums[i]);
            int job = maxi + solve(i + 1, day - 1, nums);
            ans = min(ans, job);
        }
        
        // Store the computed result before returning
        return dp[ind][day] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;

        // Initialize DP table with -1
        // dp table size: (n+1) x (d+1)
        dp.resize(n + 1, vector<int>(d + 1, -1)); 

        return solve(0, d, jobDifficulty);
    }
};