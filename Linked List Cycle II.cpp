class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* t  = head;
        ListNode* r = head;
        int flag = 0;
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        while(r!=NULL and r->next!=NULL){
            t = t->next;
            r=r->next->next;
            if(r==t){
                flag = 1;
                break;
            }
        }
        
        if(!flag){
            return NULL;
        }
        else{
            t = head;
            while(t!=r){
                t=t->next;
                r=r->next;
            }
        }
    return t; 
    }
};