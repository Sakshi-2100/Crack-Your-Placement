// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

    vector<string> backtrack(int open, int close, int n, string s, vector<string>&ans){
        if(s.size()==2*n)
            ans.push_back(s);
        if(open<n){
            s+="(";
            backtrack(open+1,close,n,s,ans);
            s.erase(s.size()-1);
        }
        if(close<open){
            s+=")";
            backtrack(open, close+1, n, s,ans);
            s.erase(s.size()-1);
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ="";
        return backtrack(0,0,n,s,ans);
    }
