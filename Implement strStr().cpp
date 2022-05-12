/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/


    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
            return -1;
        if(needle.size()==0)
            return 0;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0] && (haystack.substr(i,needle.size())==needle))
                return i;
        }
        return -1;
    }

//2 pointer approach
    int strStr(string haystack, string needle) {
        int p1 = 0; int p2 = 0;
        int idx = -1;
        
        while (p1 < haystack.size() and p2 < needle.size()) {
            if (haystack[p1] == needle[p2]) {
                if (idx < 0)
                    idx = p1;
                ++p1; ++p2;
            } else {
                if (idx >= 0) {
                    p1 = idx + 1;
                    idx = -1;   
                } else
                    ++p1;
                p2 = 0;
            }
        }
        
        return p2 < needle.size() ? -1 : idx;
    }
