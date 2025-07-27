class Solution {
public:
    int solve(int ind,vector<int>&squares,int target,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(ind  == 0){
            if(target% squares[ind]==0) return target/squares[ind];
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int notake = solve(ind-1,squares,target,dp);
        int take = INT_MAX;
        if(squares[ind]<=target){
            take = 1 + solve(ind,squares,target-squares[ind],dp);
        }

        return dp[ind][target] =  min(take,notake);
    }
    int numSquares(int n) {
        vector<int> squares;
        int i=1;
        while(i*i<= n){
            squares.push_back(i*i);
            i++;
        }
        int m = squares.size();
        vector<vector<int>> dp(m,vector<int>(n+1,-1));
        return solve(m-1,squares,n,dp);
    }
};