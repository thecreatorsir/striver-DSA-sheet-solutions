class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;
        if(headA == NULL || headB==NULL)
          return NULL;
        int count1 =0,count2=0;
        while(p!=NULL){
            p=p->next; 
            count1++;
        }
         while(q!=NULL){
            q=q->next; 
            count2++;
        }
        p=headA;
        q=headB;
        if(count1>count2){
            int diff = count1-count2;
            while(diff--)
              p=p->next;
        }
        else{
            int diff = count2-count1;
            while(diff--)
                q=q->next;
        }
        while(p!=NULL && q!=NULL){
            if(p==q)
              return p;
            p=p->next;
            q=q->next;
        }
      return NULL;   
    }
};