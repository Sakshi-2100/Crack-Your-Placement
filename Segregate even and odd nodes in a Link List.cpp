class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL)
            return head;
        Node* curr = head, *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;
        while(curr!=NULL){
            if(curr->data%2==0){
                if(evenStart==NULL){
                    evenStart = curr;
                }
                else{
                    evenEnd->next = curr;
                }
                evenEnd = curr;
            }
            else{
                if(oddStart==NULL){
                    oddStart = curr;
                }
                else{
                    oddEnd->next = curr;
                }
                oddEnd = curr;
            }
            curr=curr->next;
        }
        if(oddStart == NULL || evenStart == NULL) {
            return head;
        }
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
            return evenStart;
        
    }
};