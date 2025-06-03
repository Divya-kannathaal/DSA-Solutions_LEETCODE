class Solution {
public:
    void combo(int ind, int target, vector<int>& candidates, vector<int>& arr, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(arr);
            return;
        }

        for(int i = ind; i < candidates.size(); ++i) {
            // Skip duplicates
            if(i > ind && candidates[i] == candidates[i - 1])
                continue;

            if(candidates[i] > target)
                break;

            arr.push_back(candidates[i]);
            combo(i + 1, target - candidates[i], candidates, arr, res); // move to i+1 (not i)
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort to handle duplicates
        vector<int> arr;
        vector<vector<int>> res;
        combo(0, target, candidates, arr, res);
        return res;
    }
};
