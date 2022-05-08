/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.



Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []


Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

*/

// Brute Force           TC-O(n^2)       SC-O(1)
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
                v.push_back(nums[i]);
        }
    }
    return v;
}

// Approach 2        TC-O(nlogn)         SC-O(1)
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            v.push_back(nums[i]);
    }
    return v;
}


// Approach 3        TC-O(n)         SC-O(n)
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, bool> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (mp[nums[i]] == true)
            v.push_back(nums[i]);
        mp[nums[i]] = true;
    }
    return v;
}



// Optimal Approach      TC-O(n)         SC-O(1)
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int curr = abs(nums[i]);
        if (nums[curr - 1] < 0)
            ans.push_back(curr);
        else
            nums[curr - 1] *= -1;
    }
    return ans;
}
