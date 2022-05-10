/*

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        if(row==0)
            return ans;
        int col = matrix[0].size(), l=0, r=col-1, t=0, b=row-1, d=0;
        while(l<=r && t<=b){
            if(d==0){
                for(int i=l;i<=r;i++){
                    ans.push_back(matrix[t][i]);
                }
                t++;
                d=1;
            }
            else if(d==1){
                for(int i=t;i<=b;i++){
                    ans.push_back(matrix[i][r]);
                }
                r--;
                d=2;
            }
            else if(d==2){
                for(int i=r;i>=l;i--)
                    ans.push_back(matrix[b][i]);
                b--;
                d=3;
            }
            else if(d==3){
                for(int i=b;i>=t;i--)
                    ans.push_back(matrix[i][l]);
                l++;
                d=0;
            }
        }
        return ans;
    }
