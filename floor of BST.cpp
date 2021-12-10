void temp(Node *root,int k,int &ans){
    if (!root)
		return;
    temp(root->left,k,ans);
    if(root->data<=k) ans = root->data;
    temp(root->right,k,ans);
}
int floor(Node* root, int key)
{   int ans = -1;
	temp(root,key,ans);
    return ans;
}