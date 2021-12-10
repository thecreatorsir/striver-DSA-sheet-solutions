class Solution {
public:
   int maxPutil(TreeNode* root,int &ans){
        if(!root) return 0;
        int l = maxPutil(root->left,ans);
        int r = maxPutil(root->right,ans);
        int curr_ans = max(max(l,r) + root->val,root->val);
        int temp = max(curr_ans,l+r+root->val);
        ans = max(ans,temp);
        return curr_ans;   
    }
    int maxPathSum(TreeNode* root) {
       int ans = INT_MIN; 
       maxPutil(root,ans);
       return ans; 
    }
};