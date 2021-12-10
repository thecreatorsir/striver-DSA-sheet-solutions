class Solution {
public:
    bool helper(TreeNode*root, long MN,long MX){
        if(!root) return true;
      
        if(root->val > MN 
           and root->val < MX
           and helper(root->left,MN,root->val)
           and helper(root->right,root->val,MX)) return true;
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,INT64_MIN,INT64_MAX);
    }
};