Node * merge(Node* l1,Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->data<l2->data){
            l1->bottom = merge(l1->bottom,l2);
            return l1;
        }else{
            l2->bottom = merge(l1,l2->bottom);
            return l2;
        }
}

Node* flatten (Node* root)
{
    // Base cases
    if (root == NULL || root->next == NULL)
        return root;
  
    return merge( root, flatten(root->next) );
}