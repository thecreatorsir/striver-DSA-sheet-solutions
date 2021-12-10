class Solution {
public:
    TreeNode * helper(TreeNode *root,int val){
        if(!root || val == root->val) return root;
        if(val>root->val){
            return helper(root->right,val);
        }else{
            return helper(root->left,val);
        }
        return nullptr;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root,val);
    }
};