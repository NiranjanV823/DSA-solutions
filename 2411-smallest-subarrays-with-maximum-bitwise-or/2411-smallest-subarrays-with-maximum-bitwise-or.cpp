class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> last(32, -1); // last[i] = last index where bit i was set

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }
            int max_len = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) {
                    max_len = max(max_len, last[b]);
                }
            }
            ans[i] = max_len - i + 1;
        }

        return ans;
    }
};
