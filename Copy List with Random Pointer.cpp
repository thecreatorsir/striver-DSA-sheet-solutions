class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(!head) return head;
        
        Node *curr = head;
        Node *temp = nullptr;
        
        //copying the nodes and putting between the two nodes
        while(curr){
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr=temp;
        }
        
        // copying random pointers
        curr=head;
        while(curr and curr->next){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }
        
        //creating a copy list without disturbing the old one
        curr = head;
        Node * newhead = curr->next;
        Node  * copy = newhead;
      
        while(curr and curr->next){
            curr->next = curr->next->next;
            if(copy->next)
                copy->next = copy->next->next;
            copy=copy->next;
            curr=curr->next;
        }
        return newhead;
    }
};