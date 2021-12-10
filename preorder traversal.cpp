//recursive
class Solution {
public:
    void helper(vector<int> &ans,TreeNode *root){
        if(root==nullptr) return;
        ans.push_back(root->val);
        helper(ans,root->left);
        helper(ans,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(ans,root);
        return ans;
    }
};
//iterative
void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;

    stack<node*> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false) {
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}