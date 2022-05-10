/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


*/

// BF          TC-O(n^2)       SC-O(1)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    count++;
                if(count>floor(n/2))
                    return nums[i];
            }
        }
        return 1;
    }


//Approach 2        Using freq array or map         TC-O(n)         SC-O(n)
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        int x = floor(n/2);
        for(int i=0;i< n;i++){
            mp[nums[i]]+=1;
            if(mp[nums[i]]>x)
                ans = nums[i];
        }
        return ans;
    }

// Approach3       Sorting         TC-O(nlogn)     SC-O(1)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

