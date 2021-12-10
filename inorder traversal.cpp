//recursive
class Solution {
public:
    void helper(vector<int> &v,TreeNode * root){
        if(!root) return;
        helper(v,root->left);
        v.push_back(root->val);
        helper(v,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(v,root);
        return v;
    }
};

//iterative
class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->val); 
                node = node->right; 
            }  
        }
        return inorder; 
    }
};