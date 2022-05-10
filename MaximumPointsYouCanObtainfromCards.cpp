/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
*/

//Brute Force       Recursion       TC-O(2^k)
    void maxim(vector<int>& cardPoints, int k, int left, int right, int sum,int& maxSum){
        if(k==0){
            if(sum>maxSum)
                maxSum=sum;
            return;
        }
        k=k-1;
        sum+=cardPoints[left];
        maxim(cardPoints,k,left+1,right,sum,maxSum);
        sum=sum-cardPoints[left]+cardPoints[right];
        maxim(cardPoints,k,left,right-1,sum,maxSum);
    }

    
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum=0;
        maxim(cardPoints,k,0,cardPoints.size()-1,0,maxSum);
        return maxSum;
    }

//Approach 2
    int helper(vector<int>&cardPoints,int k, int left, int right){
        if(k==0)
            return 0;
        return max((cardPoints[left]+helper(cardPoints,k-1,left+1,right)),(cardPoints[right]+helper(cardPoints,k-1,left,right-1)));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return helper(cardPoints,k,0,cardPoints.size()-1);
    }


//Optimal Approach          Sliding Window Technique        TC-O(k)
    int maxScore(vector<int>& cardPoints, int k) {
        int tempSum=0;
        for(int i=0;i<k;i++){
            tempSum+=cardPoints[i];
        }
        int maxSum=tempSum;
        if(k==cardPoints.size())
            return tempSum;
        int right = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            tempSum=tempSum-cardPoints[i]+cardPoints[right];
            maxSum = max(maxSum,tempSum);
            right--;
        }
        return maxSum;
    }
