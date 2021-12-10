class Solution {
public:
    bool helper(TreeNode* l,TreeNode*r){
        if(!r and l) return false;
        if(!l and r) return false;
        if(!l and !r) return true;
        if(l->val == r->val 
          and helper(l->right,r->left)
          and helper(l->left,r->right))
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);
    }
};