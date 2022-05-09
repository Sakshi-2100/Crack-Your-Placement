/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

//BF            TC-O(n^3logm)       SC-O(m)
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i : s)
            ans.push_back(i);
        return ans;
    }

//Optimal Approach      TC-O(n^2)       SC-O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    int n= nums.size();
    for(int i=0;i<n-2;i++){
        if(i==0 || (i>0 && nums[i]!=nums[i-1])){
        int j=i+1,k=n-1;
        int sum = 0-nums[i];
        while(j<k){
            if(nums[j]+nums[k]==sum){
                vector<int>v;
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                v.push_back(nums[i]);
                ans.push_back(v);
                while(j<k && nums[j]==nums[j+1])
                    j++;
                while(j<k && nums[k]==nums[k-1])
                    k--;
                j++;
                k--;
            }
            else if(nums[j]+nums[k]<sum)
                j++;
            else
                k--;
        }
        }
    }
    return ans;
    }
