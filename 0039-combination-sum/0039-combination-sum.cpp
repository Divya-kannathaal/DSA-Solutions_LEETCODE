class Solution {
public:
    void combo(int ind,int target ,vector<int>& candidates,vector<int>& arr, vector<vector<int>>& res){
        if(ind==candidates.size()){
            if(target==0) res.push_back(arr);
            return;
        }
        if(candidates[ind]<=target){
            arr.push_back(candidates[ind]);
            combo(ind,target-candidates[ind],candidates,arr,res);
            arr.pop_back();
        }
        combo(ind+1,target,candidates,arr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        combo(0,target,candidates,arr,res);
        return res;
    }
};