class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen; // To track unique elements in current window
        int left = 0;            // Left pointer of sliding window
        int currentSum = 0;      // Sum of current window
        int maxSum = 0;          // Maximum sum found so far
        
        // Expand window with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If current element is duplicate, shrink window from left
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);      // Remove left element from set
                currentSum -= nums[left];    // Subtract from current sum
                left++;                      // Move left pointer forward
            }
            
            // Add current element to window
            seen.insert(nums[right]);        // Add to set
            currentSum += nums[right];       // Add to current sum
            
            // Update maximum sum if current sum is larger
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};