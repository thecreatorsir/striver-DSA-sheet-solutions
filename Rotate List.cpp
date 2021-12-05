class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int size = 0;
        
        ListNode *itr = head;
        ListNode *tail = nullptr;
       
        while(itr){
            size++;
            tail = itr;
            itr=itr->next;
            
        }
        
        k = k%size;
        if(k==0) return head;
        
        itr = head;
        
        int diff = size-k-1;
        
        while(diff){
            itr = itr->next;
            diff--;
        }
        
        ListNode *newhead = itr->next;
        
        itr->next = nullptr;
        tail->next = head;
        return newhead;
    }
};