class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0, prev = nums.back();
        for(int i = 0, n = nums.size(); i < n; ++i){
            maxi = max(maxi , abs(nums[i] - prev));
            prev = nums[i];
        }
        return maxi;
    }
};