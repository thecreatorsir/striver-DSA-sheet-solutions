class Solution {
public:
    int helper(TreeNode* root,int &ans){
        if(!root) return 0;
        int l = helper(root->left,ans);
        int r = helper(root->right,ans);
        int temp1 = max(l,r)+1;
        int temp2 = max(temp1,l+r+1);
        ans = max(ans,temp2);
        return temp1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
         return 0;
        int ans = 0;
        helper(root,ans);
        return ans-1;
    }
};