class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0);
        ListNode* p = temp, *curr = head;
        while(curr){
            if(curr->val!=val){
                p->next=curr;
                p=p->next;
            }
            curr=curr->next;
        }
        p->next=NULL;
        return temp->next;
    }
};