class Solution {
public:
    bool hasCycle(ListNode *head) {
        // slow and fast pointer approach
        ListNode* slow=head, *fast=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};