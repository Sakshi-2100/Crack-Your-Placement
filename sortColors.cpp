/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2

*/

//Brute force       TC-O(n)      SC-O(n)
void sortColors (vector<int>& nums){
    vector<int> ans;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
            c1++;
        else if(nums[i]==1)
            c2++;
        else
            c3++;
    }
    for(int i=0;i<n;i++){
        if(i<c1)
            nums[i]=0;
        else if(i>=c1 && i<c2)
            nums[i]=1;
        else
            nums[i]=2;
    }
}

//Optimal Approach      TC-O(n)      SC-O(1)
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else
                mid++;
        }
