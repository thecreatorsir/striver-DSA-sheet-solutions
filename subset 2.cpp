//shorter method
class Solution {
private: 
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)     {
        ans.push_back(ds);
        for(int i = ind;i<nums.size();i++) {
            if(i!=ind && nums[i] == nums[i-1]) continue; 
            ds.push_back(nums[i]); 
            findSubsets(i+1, nums, ds, ans); 
            ds.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        sort(nums.begin(), nums.end()); 
        findSubsets(0, nums, ds, ans);
        return ans; 
    }
};
// recursive
class Solution {
public:
    void solver(int ind,vector<int> temp,vector<int> &nums,int n,set<vector<int>> &s,vector<vector<int>> &subset){
        if(ind==n){
            if(s.find(temp)==s.end()){
                s.insert(temp);
                subset.push_back(temp);
            }
            return;
        }
        //don't take
        solver(ind+1,temp,nums,n,s,subset);
        //take
        temp.push_back(nums[ind]);
        solver(ind+1,temp,nums,n,s,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subset;
        vector<int> temp;
        set<vector<int>> s;
        int n= nums.size();
        solver(0,temp,nums,n,s,subset);
        return subset;
    }
};


// iterative approach
class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> s;
        ans.push_back(temp);
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int sz = ans.size();
            for(int j=0;j<sz;j++){
                temp = ans[j];
                temp.push_back(nums[i]);
                if(s.find(temp)==s.end()){
                    s.insert(temp);
                    ans.push_back(temp);
                }
            }
        }        
        return ans;
    }
};


