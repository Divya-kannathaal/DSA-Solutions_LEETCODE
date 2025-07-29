class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // Track the rightmost position where each bit appears as 1
        vector<int> lastPos(30, -1);
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Update lastPos array with current number's bits
            for (int bit = 0; bit < 30; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastPos[bit] = i;
                }
            }
            
            // Find the farthest position we need to reach
            // to get maximum possible OR starting from position i
            int maxReach = i;
            for (int bit = 0; bit < 30; bit++) {
                if (lastPos[bit] != -1) {
                    maxReach = max(maxReach, lastPos[bit]);
                }
            }
            
            // Length of smallest subarray = maxReach - i + 1
            result[i] = maxReach - i + 1;
        }
        
        return result;
    }
};