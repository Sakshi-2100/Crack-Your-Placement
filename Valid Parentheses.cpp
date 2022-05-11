/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        return false;
    }
