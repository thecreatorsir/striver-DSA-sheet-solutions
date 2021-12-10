void helper(Node *root,int level,vector<int> &v){
    if(!root)
   return;
   if(level==v.size())
   v.push_back(root->data);
   helper(root->left,level+1,v);
   helper(root->right,level+1,v);
}

vector<int> leftView(Node *root)
{
   vector<int>v;
   helper(root,0,v);
  return v;
}