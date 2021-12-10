class BSTIterator 
{
public:
    stack<TreeNode*> st;
    void travelLeft(TreeNode* root)
    {
         while(root != nullptr)
         {
             st.push(root);
             root = root->left;
         }
    }
    BSTIterator(TreeNode* root) 
    {
         travelLeft(root);
    }
    
    int next() 
    {
         TreeNode* temp = st.top();
         st.pop();
        
         travelLeft(temp->right);
        
         return temp->val;
    }
    
    bool hasNext() 
    {
         return !st.empty();    
    }
};