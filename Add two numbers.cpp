class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* p = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        long long num1 =0, num2=0;
        while(l1!=NULL || l2!=NULL){
            if(l1){
                num1 = (num1*10)+l1->val;
                l1=l1->next;
            }
            if(l2){
                num2 = (num2*10)+l2->val;
                l2=l2->next;
            }
        }
        long long ans = num1+ num2;
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        cout<<ans<<endl;
        if(ans==0)
            return temp;
        while(ans!=0){
            int rem = ans%10;
            p->next = new ListNode(rem);
            ans = ans/10;
            p=p->next;
        }
        return temp->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        int sum =0, carry=0;
        while(l1!=NULL || l2!=NULL){
            if(l1){
                sum = l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2=l2->next;
            }
            if(sum+carry<=9){
                temp->next = new ListNode(sum+carry);
                carry=0;
            }
            else{
                temp->next = new ListNode((sum+carry)%10);
                carry = (sum+carry)/10;
            }
            temp=temp->next;
            sum=0;
        }
        if(carry)
            temp->next = new ListNode(carry);
        return p->next;
    }
};