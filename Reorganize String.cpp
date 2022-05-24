/*

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.


*/


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.length();i++)
           mp[s[i]]++;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        // while(!pq.empty()){
        //     cout<<pq.top().first<<' '<<pq.top().second;
        //     pq.pop();
        // }
        string ans;
        char c = pq.top().second;
        int f = pq.top().first;
        f--;
        pq.pop();
        ans+=c;
        while(!pq.empty()){
            char ch = pq.top().second;
            int freq = pq.top().first;
            ans+=ch;
            freq--;
            pq.pop();
            if(f>0){
                pq.push({f,c});
            }
            c = ch;
            f = freq;
        }
        if(f>0)
            return "";
        return ans;
    }
};