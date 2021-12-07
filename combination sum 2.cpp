class Solution {
    public: 
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&temp) {
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        for(int i = ind;i<arr.size();i++) {
            if(i>ind && arr[i]==arr[i-1]) continue; 
            temp.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, temp); 
            temp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> temp; 
        findCombination(0, target, candidates, ans, temp); 
        return ans; 
    }
};