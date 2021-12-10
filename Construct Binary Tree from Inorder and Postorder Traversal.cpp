class Solution {
public:
    map<int,int> mp;
    TreeNode * helper(vector<int> postorder,vector<int> inorder,int istart,int iend,int pstart,int pend){
        if(istart > iend || pstart > pend) return NULL;
        int root = postorder[pend];
        TreeNode * temp =new TreeNode(root);
        int index = mp[root];
        temp -> left = helper(postorder,inorder,istart,index-1,pstart,pstart+index-istart-1);
        temp ->right = helper(postorder,inorder,index+1,iend,pstart+index-istart,pend-1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        return helper(postorder,inorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};