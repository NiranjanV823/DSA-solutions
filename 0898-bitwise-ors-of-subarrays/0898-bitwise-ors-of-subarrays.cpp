class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result; // Store all distinct OR values
        unordered_set<int> current; // OR values for subarrays ending at current position
        
        for (int num : arr) {
            unordered_set<int> next; // OR values for subarrays ending at current num
            
            // Add the current number itself (subarray of length 1)
            next.insert(num);
            
            // For each OR value ending at previous position,
            // compute OR with current number
            for (int prev : current) {
                next.insert(prev | num);
            }
            
            // Add all new OR values to our result set
            for (int val : next) {
                result.insert(val);
            }
            
            // Update current for next iteration
            current = next;
        }
        
        return result.size();
    }
};