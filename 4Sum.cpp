/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

//BF            TC-O(n^4 log m)           SC-O(log m)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    for(int l=k+1;l<nums.size();l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int>v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(nums[l]);
                            sort(v.begin(),v.end());
                            s.insert(v);
                        }
                    }
                }
            }
        }
        for(auto i : s)
            ans.push_back(i);
        return ans;
    }

//Optimal Approach      TC-O(n^3)       SC-O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int x = target-nums[i];
                for(int j=i+1;j<nums.size()-2;j++){
                    if(j==i+1||(j>1 && nums[j]!=nums[j-1])){
                        int sum = x-nums[j];
                        int k=j+1,l=nums.size()-1;
                        while(k<l){
                            if(nums[k]+nums[l]==sum){
                                vector<int>v;
                                v.push_back(nums[j]);
                                v.push_back(nums[k]);
                                v.push_back(nums[i]);
                                v.push_back(nums[l]);
                                ans.push_back(v);
                                while(k<l && nums[k]==nums[k+1]) k++;
                                while(k<l && nums[l]==nums[l-1]) l--;
                                k++;
                                l--;
                            }
                            else if(nums[k]+nums[l]<sum)
                                k++;
                            else
                                l--;
                        }
                    }
                }
            }
        }
        return ans;
    }

