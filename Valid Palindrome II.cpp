// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

    bool validPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1, count1=0, count2=0;
        while(i<j){
            if(s[i] != s[j])
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            i++; j--;
        }
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) 
                return false;
            i++; j--;
        }
        return true;
    }

