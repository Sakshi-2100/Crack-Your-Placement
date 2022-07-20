class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* dummy = head;
        int count=0;
        while(dummy!=NULL){
            dummy=dummy->next;
            count++;
        }
        int ans =0;
        count=count-1;
        while(head!=NULL){
            ans+=head->val*pow(2,count);
            count--;
            head=head->next;
        }
        return ans;
    }
};