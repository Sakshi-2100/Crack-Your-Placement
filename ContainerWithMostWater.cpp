/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

//Brute Force       TC-O(n^2)       SC-O(1)

int maxArea(vector<int>& height)
{
    int len = height.size();
    int area = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            // Calculating the max area
            area = max(area, min(height[j], height[i]) * (j - i));
        }
    }
    return area;
}

//Optimal Approach      TC-O(n)         SC-O(1)
int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len -1;
        int area = 0;
     
        while (l < r){
        // Calculating the max area
            area = max(area, min(height[l],
                        height[r]) * (r - l));
                         
            if (height[l] < height[r])
                l += 1;
                 
            else
                r -= 1;
    }
    return area;
    }