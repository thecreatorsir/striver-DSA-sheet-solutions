class Solution {
public:
    TreeNode * preorderfill(vector<int>nums,int start,int end){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = preorderfill(nums,start,mid-1);
        temp->right = preorderfill(nums,mid+1,end);
        return temp;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preorderfill(nums,0,nums.size()-1);
    }
};