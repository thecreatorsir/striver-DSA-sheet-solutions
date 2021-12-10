class Solution {
public:
 
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                Node * temp = q.front();
                q.pop();
                if(sz!=1)
                    temp->next = q.front();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sz--;
            } 
        }
        return root;
    }
};