long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long N = 1000000007;
  long long num1 =0, num2=0;
  while(l1!=NULL || l2!=NULL){
      if(l1){
          num1 = (num1*10)%N + l1->data;
          l1=l1->next;
      }
      if(l2){
          num2 = (num2*10)%N + l2->data;
          l2=l2->next;
      }
  }
  long long ans = ((num1%N)*(num2%N))%N;
  return ans;
}