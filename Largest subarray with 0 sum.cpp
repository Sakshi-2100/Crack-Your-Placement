/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i


*/


// BF O(n^2)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int>ans(0);
        for(int i=0;i<n;i++){
            int sum =0;
            vector<int>v(0);
            for(int j=i;j<n;j++){
                sum+=A[j];
                v.push_back(A[j]);
                if(sum==0){
                    if(v.size()>ans.size()){
                        ans = v;
                    }
                }
            }
        }
        return ans.size();
    }
};


//Optimal       O(n)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int> prefixSum(n+1);
        prefixSum[0]=A[0];
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+A[i];
        unordered_map<int,int>mp;
        int maximum =0;
        for(int i=0;i<n;i++){
            if(prefixSum[i]==0)
                maximum = max(maximum,i+1);
            else if(mp.find(prefixSum[i])!=mp.end()){
                maximum = max(maximum, i-mp[prefixSum[i]]);
            }
            else
                mp[prefixSum[i]]=i;
        }
        return maximum;
    }
};
