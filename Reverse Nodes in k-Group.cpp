class Solution {
public:
    ListNode* Reverse(ListNode* head){

	ListNode* curr = head;
	ListNode* prev = nullptr;
    ListNode* next = nullptr;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode *prev = NULL;
         ListNode *curr = head;
         ListNode *next = head;
        int i=0;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            if(i == k-1){
			head->next = reverseKGroup(curr, k);
			return prev;
		}
            i++;
        }
        return Reverse(prev);
    }
};