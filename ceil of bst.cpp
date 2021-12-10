void temp(node *root,int k,int &ans){
    if (!root)
		return;
    temp(root->left,k,ans);
    if(root->key>=k && ans==-1) ans = root->key;
    temp(root->right,k,ans);
}
int Ceil(node* root, int key)
{   int ans = -1;
	temp(root,key,ans);
    return ans;
}