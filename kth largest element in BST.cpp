void solver(TreeNode *root,int k,int &ans,int &count){
    if(!root) return;
    solver(root->right,k,ans,count);
    count++;
    if(count==k){
        ans = root->val;
    }
    solver(root->left,k,ans,count);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1,count=0;
    solver(root,k,ans,count);
    return ans;
}
