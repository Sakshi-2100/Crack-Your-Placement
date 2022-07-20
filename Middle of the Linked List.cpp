class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = head;
        int count=0;
        while(dummy!=NULL){
            count++;
            dummy=dummy->next;
        }
        int x=0;
        if(count%2==0){
            x=(count/2)+1;
        }
        else
            x=(count+1)/2;
        count=1;
        while(count<x){
            head=head->next;
            count++;
        }
        return head;
    }
};

// TC- O(N)+O(N/2)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s=head, *f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};

// Tortoise method- slow pointer by 1 and fast pointer by 2
// TC-O(N/2)