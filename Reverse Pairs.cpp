/*

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1


*/


//BF        TC-O(n^2)           SC-O(1) 
    int reversePairs(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] > 2 *nums[j])
                    count++;
            }
        }
        return count;
    }