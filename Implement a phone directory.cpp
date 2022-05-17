/*

Problem Statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.
Note :
If no suggestions are found, return an empty 2D array.
For Example :

In the above example everytime we enter a character, a few suggestions display the strings which contain the entered string as prefixes.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array/list.

The second line contains ‘N’ single space-separated strings denoting the contacts of the given array/list or contact list.

The third line contains a single string denoting the query string.
Output Format :
For each test case, for the given query string you need to print all the possible contacts or suggestions that are present in the given directory corresponding to each entered character in the given query string. 
If no suggestions are found then the message “No suggestions found” is printed.
Note :
You do not need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= len <= 10
ARR[i] contains lowercase English alphabets.

All the given strings contain lowercase English alphabets.

Time Limit: 1 sec.
Sample Input 1 :
2
5
cod coding codding code coly
coding
2
ninjas coding
ninja
Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
ninjas
ninjas
ninjas
ninjas
ninjas
Explanation To Sample Input 1 :
In the first test case, 
The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestion for “codi” is {“coding”}.
The suggestion for “codin” is {“coding”}.
The suggestion for “coding” is {“coding”}.

In the second test case, 
The suggestion for “n” is {“ninjas”}.
The suggestion for “ni” is {“ninjas”}.
The suggestion for “nin” is {“ninjas”}.
The suggestion for “ninj” is {“ninjas”}.
The suggestion for “ninja” is {“ninjas”}.
Sample Input 2 :
3
2
coding ninjas
cell
2
ab abc
a
2
ab abc
b
Sample Output 2 :
coding
ab abc
No suggestions found
Explanation To Sample Input 2 :
In the first test case, 
The suggestion for “c” is {“coding”}.
For the rest of the letters, there are no suggestions.

In the second test case,
The suggestion for “a” is {“ab”, “abc”}.

In the third test case, no suggestions are found.
Previous
Next

 */
class TrieNode{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		
		TrieNode(char ch){
			data= ch;
			for(int i=0;i<26;i++)
				children[i]=NULL;
			isTerminal=false;
		}
};


class Trie {

public:

    /** Initialize your data structure here. */
	TrieNode* root;
    Trie() {
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
		}
		insertUtil(child,word.substr(1));
	}
    void insert(string word) {
	return insertUtil(root,word);
    }
	void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
		if(curr->isTerminal)
			temp.push_back(prefix);
		for(char ch = 'a'; ch<='z';ch++){
			TrieNode* next = curr->children[ch-'a'];
			if(next!=NULL){
				prefix.push_back(ch);
				printSuggestions(next,temp,prefix);
				prefix.pop_back();
			}
		}
	}
	vector<vector<string>>getSuggestions(string str){
		TrieNode* prev = root;
		vector<vector<string>>output;
		string prefix = "";
		for(int i=0;i<str.length();i++){
			char lastch = str[i];
			prefix.push_back(lastch);
			int index = lastch-'a';
			TrieNode* curr = prev->children[index];
			//Not present
			if(curr==NULL)
				break;
			//found
			vector<string> temp;
			printSuggestions(curr,temp,prefix);
			
			output.push_back(temp);
			temp.clear();
			prev = curr;
		}
		return output;
	}
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
	Trie* t = new Trie();
	for(int i=0;i<contactList.size();i++){
		string s = contactList[i];
		t->insert(s);
	}
	return t->getSuggestions(queryStr);
}