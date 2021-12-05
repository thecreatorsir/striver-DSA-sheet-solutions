class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *rabbit=head;
        ListNode *turtle=head;
        while(rabbit and rabbit->next){
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if(rabbit==turtle) return true;
        }
        return false;
    }
};