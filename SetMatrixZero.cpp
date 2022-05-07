/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]


Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

// Brute force       TC-O(n*m+(n+m))       SC-O(1)
// If only positive numbers are present or no number is int min

void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                int ind = i - 1;
                while (ind >= 0)
                {
                    if (matrix[ind][j] != 0)
                        matrix[ind][j] = INT_MIN;
                    ind--;
                }
                ind = i + 1;
                while (ind < row)
                {
                    if (matrix[ind][j] != 0)
                        matrix[ind][j] = INT_MIN;
                    ind++;
                }
                ind = j - 1;
                while (ind >= 0)
                {
                    if (matrix[i][ind] != 0)
                        matrix[i][ind] = INT_MIN;
                    ind--;
                }
                ind = j + 1;
                while (ind < col)
                {
                    if (matrix[i][ind] != 0)
                        matrix[i][ind] = INT_MIN;
                    ind++;
                }
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0 || matrix[i][j] == INT_MIN)
                matrix[i][j] = 0;
        }
    }
}

// Approach 2- Using two dummy arrays        TC-O(n*m)       SC-O(n)+O(m)
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    vector<int> d1(row, -1), d2(col, -1);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                d1[i] = 0;
                d2[j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (d1[i] == 0 || d2[j] == 0)
                matrix[i][j] = 0;
        }
    }
}

//Optimal Approach      TC-O(n*m)       SC-O(1)
//Instead of taking two dummy arrays we can take first row and first column for same work
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1,row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)
                col0=0;
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0==0)
                matrix[i][0]=0;
        }
    }
