/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/
//Brute Force       O(n^2)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=0;
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            while(heights[left]>=heights[i])
                left--;
            while(heights[right]>=heights[i])
                right++;
            area= max(area,(right-left-1)*heights[i]);
        }
        return area;
    }

//Optimal       O(n)        Using stack prev smaller and next smaller storing indexes
    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int>ps(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                ps[i]=-1;
            else
                ps[i]=s.top();
            s.push(i);
        }
        return ps;
    }
    
        vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int>ns(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                ns[i]=n;
            else
                ns[i]=s.top();
            s.push(i);
        }
        return ns;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>ps=prevSmaller(heights);
        vector<int>ns=nextSmaller(heights);
        int area=0;
        for(int i=0;i<heights.size();i++){
            int curr = (ns[i]-ps[i]-1)*heights[i];
            area=max(area,curr);
        }
        return area;
    }

