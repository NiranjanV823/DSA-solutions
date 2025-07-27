class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ;
        int left = -1;
        int right = 0;
        vector<int> temp; 
        for(int i=0; i<n; i++){
            if(temp.empty() || temp.back()!= nums[i]) temp.push_back(nums[i]);
        }

        n = temp.size();

        for(int i=0; i<n; i++){
            right = i+1;
            left = i-1;
            
            if(left<0 || right>=n) continue;
            // while(left>=0 && temp[left]==temp[i]) left--;
            // while(right<n && temp[right]==temp[i]) right++;
            // if(left<0 || right>=n) continue;
            if(temp[i]>temp[left] && temp[i]>temp[right]) count++;
            if(temp[i]<temp[left] && temp[i]<temp[right]) count++;
        }

        // int prev;
        // for(int i=1; i<n; i++){
        //     prev = i-1;
        //     if(nums[i]==nums[prev]) count--;
        // }
        return count;
    }
};