class node {
    public: 
    int maxNode, minNode, maxSum;
    node(int minNode, int maxNode, int maxSum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
};
class Solution {
    private :
    int ans=0;
    node* maxSumBSTHelper(TreeNode* root) {
        if (root == nullptr) {
            return new node(INT_MAX, INT_MIN, 0);
        }
        node *left = maxSumBSTHelper(root->left);
        node *right = maxSumBSTHelper(root->right);
        if (!(     left != nullptr             
                && right != nullptr            
                && root->val > left->maxNode       
                && root->val < right->minNode))    
            return nullptr;
   
            int sum = left->maxSum + right->maxSum + root->val;
            ans = max(ans,sum);
            return new node(min(root->val, left->minNode), max(root->val, right->maxNode),sum);
    }
public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return ans;
    }
};