#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Step 1: Create a min heap (using greater<int>)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 2: Loop through the array
        for (int num : nums) {
            minHeap.push(num); // Add current number to heap

            // Step 3: If heap grows larger than k, remove the smallest
            if (minHeap.size() > k) {
                minHeap.pop(); // Keeps only k largest elements
            }
        }

        // Step 4: Return the top of the heap (the kth largest element)
        return minHeap.top();
    }
};
