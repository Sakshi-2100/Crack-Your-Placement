/*

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

*/

    bool backtrack(vector<vector<char>>& board, int row, int col, string word, int index){
        if(index>=word.size())
            return true;
        if(row<0 || row==board.size() || col<0 || col==board[0].size() || board[row][col]!=word[index])
            return false;
        board[row][col]='#';
        int rowOff[4] = {0,1,0,-1};
        int colOff[4] = {1,0,-1,0};
        bool res = false;
        for(int d=0;d<4;d++){
            res = backtrack(board,row+rowOff[d], col+colOff[d],word,index+1);
            if(res)
                break;
        }
        board[row][col]=word[index];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
