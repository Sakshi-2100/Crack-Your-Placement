/*

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1


*/


//O(n^2)
class Solution {
public:
    bool find(int n, vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n)
                return true;
        }
        return false;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i=1;i<=nums.size();i++){
            if(find(i,nums))
                continue;
            else
                return i;
        }
        return nums.size()+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                pq.push(nums[i]);
        }
        if(pq.empty())
            return 1;
        if(pq.top()!=1)
            return 1;
        int ans=0;
        int x = pq.top();
        pq.pop();
        while(!pq.empty()){
            int y = pq.top();
            pq.pop();
            if(y-x>1){
                ans = x+1;
                break;
            }
            x=y;
        }
        if(ans==0)
            return x+1;
        return ans;
    }
};