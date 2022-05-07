/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

//Brute force           TC-O(n*n)           SC-O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }


//Optimal Approach-2 pointer approach           TC-O(nlogn)     SC-O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        vector<int> ans;
        int i=0,j=nums.size()-1,left=0,right=0;
        while(i<j){
            if(temp[i]+temp[j]==target){
                left=temp[i];
                right=temp[j];
                break;
            }
            else if(temp[i]+temp[j]>target)
                j--;
            else
                i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==left)
                ans.push_back(i);
            else if(nums[i]==right)
                ans.push_back(i);
            if(ans.size()==2)
                break;
        }
        return ans;
    }

