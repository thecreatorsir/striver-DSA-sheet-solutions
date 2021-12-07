class Solution {
public:
    void helper(int ind,vector<vector<int>> &ans,vector<int> &temp,vector<int> &ca,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)
            return;
        for(int i=ind;i<ca.size();i++){
            temp.push_back(ca[ind]);
            helper(i,ans,temp,ca,target-ca[ind]);
            //backtracking step
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& ca, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,ans,temp,ca,target);
        return ans;
    }
};
