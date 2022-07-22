// TC-O(N*K)
class Solution {
public:
     ListNode* merge(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) 
            return NULL;
        if(lists.size()==1)
            return lists[0];
       ListNode* helper = lists[0];
        for(int i=1;i<lists.size();i++){
            helper = merge(helper,lists[i]);
        }
        return helper;
    }
};
//  TC-O(NlogK)     SC-O(1)
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val>l2->val)
            swap(l1,l2);
        ListNode* result = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp = NULL;
            while(l1!=NULL && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            swap(l1,l2);
            temp->next = l1;
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        int i=0;
        int last = lists.size()-1;
        int j;
        while(last!=0){
             j = last;
             i=0;
            while(i<j){
                lists[i]=merge(lists[i],lists[j]);
                i++;
                j--;
                if(i>=j)
                    last=j;
            }
        }
        return lists[0];
    }
};