// TC-O(N+M)       SC-O(N+M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp, *p = list1, *q = list2;
        while(p!=NULL && q!=NULL){
            if(p->val<=q->val){
                curr->next=p;
                p=p->next;
            }
            else{
                curr->next=q;
                q=q->next;
            }
            curr=curr->next;
        }
        if(p)
            curr->next=p;
        else
            curr->next=q;
        return temp->next;
    }
};

// TC -O(N+M)          SC-O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val>l2->val)
            swap(l1,l2);
        ListNode* res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp = NULL;
            while(l1!=NULL && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            swap(l1,l2);
            temp->next=l1;
        }
        return res;
    }
};