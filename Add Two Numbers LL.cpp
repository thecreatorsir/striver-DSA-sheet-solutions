class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        int sum=0,carry=0;
        ListNode* a = l1,*b=l2;
        
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        
        while(a and b){
            sum = (a->val+b->val+carry)%10;
            carry = (a->val+b->val+carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next; 
            a=a->next;
            b=b->next;
        }
        while(a){
          sum = (a->val+carry)%10;
            carry = (a->val+carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next;   
             a=a->next;
        }
          while(b){
          sum = (b->val+carry)%10;
            carry = (b->val+carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next; 
            b=b->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
            temp = temp->next;   
        }
        return head->next;
    }
};