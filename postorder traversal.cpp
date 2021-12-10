//recursive
class Solution {
public:
    vector<int> v;
    void helper(TreeNode *root){
        if(!root) return;
        helper(root->left);
        helper(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        v.clear();
        helper(root);
        return v;
    }
};

//iterartive

void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;

    stack<Node *> s1, s2;

    s1.push(root);
    Node* node;
 
    while (!s1.empty()) {
    
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}