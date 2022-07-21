
// TC-O(N*M)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p= headA, *q = headB;
        while(p!=NULL){
            while(q!=NULL){
                if(p==q)
                    return p;
                q=q->next;
            }
            q=headB;
            p=p->next;
        }
        return NULL;
    }
};


// TC-O(N+M)       SC-O(N)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p =headA, *q=headB;
        map<ListNode*, bool>mp;
        while(p!=NULL){
            mp[p]=true;
            p=p->next;
        }
        while(q!=NULL){
            if(mp[q]==true)
                return q;
            q=q->next;
        }
        return NULL;
    }
};

// TC-O(N+M)       SC-O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p =headA, *q=headB;
        int count1=0, count2=0;
        while(p!=NULL){
            count1++;
            p=p->next;
        }
        while(q!=NULL){
            count2++;
            q=q->next;
        }
        int ans = abs(count1-count2);
        p=headA, q=headB;
        int i=0;
        while(i<ans){
            if(count1>count2)
                p=p->next;
            else
                q=q->next;
            i++;
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
// TC-O(N+M)       SC-O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode* p = headA, *q = headB;
        while(p!=NULL || q!=NULL){
            if(p==q)
                return p;
            p= p==NULL ? headB : p->next;
            q= q==NULL ? headA : q->next;
        }
        return NULL;
    }
};