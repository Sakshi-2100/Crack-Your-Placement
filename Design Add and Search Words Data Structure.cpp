/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.

*/

class TrieNode{
  public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    void addWordUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        int index = word[0]-'a';
        if(root->children[index]!=NULL)
            child = root->children[index];
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        return addWordUtil(child,word.substr(1));
    }
    
    void addWord(string word) {
        return addWordUtil(root,word);
    }
    
    bool searchWord(TrieNode* root, string word){
        if(word.length()==0)
            return root->isTerminal;
        TrieNode* child;
        if(word[0]=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    if(searchWord(root->children[i],word.substr(1)))
                        return true;
                }
            }
            return false;
        }
        int index = word[0]-'a';
        if(root->children[index]!=NULL)
            child = root->children[index];
        else
            return false;
        return searchWord(child,word.substr(1));
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
};
