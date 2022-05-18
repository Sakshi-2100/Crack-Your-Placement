/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/
//Brute Force           O(n*k)
    int findKthLargest(vector<int>& nums, int k) {
        int maximum = INT_MIN;
        while(k--){
            maximum = INT_MIN;
            int j = -1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>maximum){
                    j = i;
                    maximum = nums[i];
                }
            }
            nums[j]=INT_MIN;
        }
        return maximum;
    }


//Approach 2 Sorting            O(nlogn)
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }

//Optimal       SC-O(k)         TC-O(n + (k)*log(k))

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        k=k-1;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }


//Most Optimal    SC-O(k)       O(K + (n-k)*log(k))
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq; //Minheap
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};