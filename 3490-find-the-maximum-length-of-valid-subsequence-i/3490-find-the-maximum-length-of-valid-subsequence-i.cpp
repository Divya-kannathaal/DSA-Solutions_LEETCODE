class Solution {
public:
    static int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return 2;  // Special case

        int len[3] = {0};  // [evenCount, oddCount, alternatingCount]
        bool prevParity = nums[0] % 2;

        len[prevParity]++;     // Count first number in even/odd
        len[2] = 1;            // Start alternating count with first element

        for (int i = 1; i < n; ++i) {
            bool currParity = nums[i] % 2;
            len[currParity]++;  // Increase even or odd count

            // If parity changed from previous number, count it in alternating
            if (currParity != prevParity) {
                len[2]++;
                prevParity = currParity;  // Update last parity
            }
        }

        return max({len[0], len[1], len[2]});
    }
};