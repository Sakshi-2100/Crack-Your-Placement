/*

Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s. 

Example: 

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8
Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 

Input:
0 1 1
1 1 1
0 1 1      
Output:
6
Explanation : 
The largest rectangle with only 1's is from 
(0, 1) to (2, 2) which is
1 1
1 1
1 1

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int>& currRow){
        int n = currRow.size();
        vector<int>ps(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && currRow[s.top()]>=currRow[i])
                s.pop();
            if(s.empty())
                ps[i]=-1;
            else
                ps[i]=s.top();
            s.push(i);
        }
        return ps;
    }
    
        vector<int> nextSmaller(vector<int>& currRow){
        int n = currRow.size();
        vector<int>ns(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && currRow[s.top()]>=currRow[i])
                s.pop();
            if(s.empty())
                ns[i]=n;
            else
                ns[i]=s.top();
            s.push(i);
        }
        return ns;
    }

    int largestRectangleArea(vector<int>& currRow) {
        vector<int>ps=prevSmaller(currRow);
        vector<int>ns=nextSmaller(currRow);
        int area=0;
        for(int i=0;i<4;i++){
            int curr = (ns[i]-ps[i]-1)*currRow[i];
            area=max(area,curr);
        }
        return area;
    }
int maxSizeRectBinarySubmatrixWithAllOnes(vector<vector<int>>& arr,int row, int col){
    vector<int>currRow = arr[0];
    int maxAns = largestRectangleArea(currRow);
    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==1)
                currRow[j]+=1;
            else
                currRow[j]=0;
        }
        int tempAns = largestRectangleArea(currRow);
        maxAns= max(maxAns, tempAns);
    }
    return maxAns;
}
int main() {
	vector<vector<int>>arr = {
	    {0, 1, 1, 0,},
{1, 1, 1, 1},
{1, 1, 1, 1},
{1, 1, 0, 0}
	};
	int ans = maxSizeRectBinarySubmatrixWithAllOnes(arr,4,4);
	cout<<ans;
	return 0;
}