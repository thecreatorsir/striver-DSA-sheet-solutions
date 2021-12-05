class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode * p1 = head;
        ListNode * p2 = head;
        
        while(p2 and p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode *curr = head;
        ListNode *next = head;
        ListNode *prev = nullptr;
        
        while(curr!=p1){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = p1;
        
        //for odd number of nodes
        if(p2)
            p1=p1->next;
        
        ListNode * p3 = prev;
        while(p1){
            if(p1->val!=p3->val)
                return false;
            p1=p1->next;
            p3=p3->next;
        }
        return true;
    }
};