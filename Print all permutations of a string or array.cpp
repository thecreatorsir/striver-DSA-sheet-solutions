class Solution {
    vector<vector<int>> ans;
public:
    void solver(vector<int> arr,int l,int r){
        //base case
        if(l==r){
            ans.push_back(arr);
            return;
        }
       for(int i=l;i<=r;i++){
            //fixing one value
            swap(arr[l],arr[i]);
            solver(arr,l+1,r);
            //backtrack
            swap(arr[l],arr[i]);
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solver(nums,0,n-1);
        return ans;
    }
};