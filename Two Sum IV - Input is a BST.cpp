class Solution {
public:
    unordered_map<int,int>m;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(m[k-root->val]) return true;
        m[root->val]=1;
        return findTarget(root->left, k)||findTarget(root->right,k);
    }
};