/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/


    int minLength(vector<string> &strs){
        int n = strs.size();
        int mini = strs[0].length();
        for(int i=1;i<n;i++){
            if(strs[i].length()<mini)
                mini = strs[i].length();
        }
        return mini;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size();
        int mini = minLength(strs);
        for(int i=0;i<mini;i++){
            char curr = strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=curr)
                    return ans;
            }
            ans+=curr;
        }
        return ans;
    }


//Using Tries
class TrieNode{
	public:
		char data;
		TrieNode* children[26];
        int childrenCount;
		bool isTerminal;
		
		TrieNode(char ch){
			data= ch;
			for(int i=0;i<26;i++)
				children[i]=NULL;
            childrenCount=0;
			isTerminal=false;
		}
};

class Trie {

public:

    /** Initialize your data structure here. */
	TrieNode* root;
    Trie(char ch) {
	root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
	void insertUtil(TrieNode* root, string word){
		if(word.length()==0){
			root->isTerminal = true;
			return;
		}
		int index = word[0]-'a';
		TrieNode* child;
		if(root->children[index]!=NULL)
			child = root->children[index];
		else{
			child = new TrieNode(word[0]);
			root->children[index]=child;
            root->childrenCount++;
		}
		insertUtil(child,word.substr(1));
	}
    void insert(string word) {
	return insertUtil(root,word);
    }
    void lcp(string str, string &ans){
        for(int i=0;i<str.size();i++){
            char ch = str[i];
            if(root->childrenCount==1){
                ans.push_back(ch);
                int index = ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal)
                break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie('\0');
        string ans = "";
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()==0)
                return ans;
            t->insert(strs[i]);
        }
        string first = strs[0];
        t->lcp(first,ans);
        return ans;
    }
};