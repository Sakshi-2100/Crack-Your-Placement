class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        stack<int>s;
        while(p!=NULL){
            s.push(p->val);
            p=p->next;
        }
        p=head;
        while(p!=NULL){
            if(p->val!=s.top())
                return false;
            s.pop();
            p=p->next;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
            slow=slow->next;
        ListNode* dummy = slow;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(dummy){
            next = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = next;
        }
        dummy = prev;
        while(dummy!=NULL){
            if(head->val!=dummy->val)
                return false;
            head = head->next;
            dummy = dummy->next;
        }
        return true;
    }
};