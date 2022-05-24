/*

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.


*/

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                v.push_back(matrix[i][j]);
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=0,count=0;
        while(count<k && i<m){
            pq.push(matrix[i][j]);
            count++;
            j++;
            if(j==n){
                i++;
                j=0;
            }
        }
        while(i<m){
            if(matrix[i][j]<pq.top()){
                pq.pop();
                pq.push(matrix[i][j]);
            }
            j++;
            if(j==n){
                i++;
                j=0;
            }
        }
        return pq.top();
    }
};


class Solution {
public:
    int findRank(vector<vector<int>>& matrix, int mid){
        int rank = 0, n= matrix.size(), j=0, i=n-1;
        while(i>=0 && j<n){
            if(matrix[i][j]>mid)
                i--;
            else{
                j++;
                rank+=i+1;
            }
        }
        return rank;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0], high = matrix[matrix.size()-1][matrix[0].size()-1];
        
        //Binary search on range rather than index
        
        while(low<high){
            int mid = low+(high-low)/2;
            int rank = findRank(matrix,mid);
            if(rank<k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};