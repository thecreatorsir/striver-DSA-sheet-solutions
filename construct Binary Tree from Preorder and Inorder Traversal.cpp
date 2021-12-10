class Solution {
public:
    int idx;
    map<int,int> mp;
    TreeNode * helper(vector<int> preorder,vector<int> inorder,int start,int end){
        if(start > end) return NULL;
        int root = preorder[idx++];
        TreeNode * temp =new TreeNode(root);
        int index = mp[root];
        temp -> left = helper(preorder,inorder,start,index-1);
        temp ->right = helper(preorder,inorder,index+1,end);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int n = inorder.size();
        return helper(preorder,inorder,0,n-1);
    }
};