class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(slow!=NULL && fast!=NULL){
            if(slow->val==fast->val){
                fast=fast->next;
                slow->next=fast;
            }
            else{
                slow=slow->next;
                fast=fast->next;
            }
        }
        return head;
    }
};