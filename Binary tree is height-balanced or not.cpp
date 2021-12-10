class Solution {
public:
    int height(TreeNode *root){
        return !root?0:1 + max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return !root || (abs(height(root->left)-height(root->right))<=1 and isBalanced(root->left) and isBalanced(root->right))?1:0;
    }
};