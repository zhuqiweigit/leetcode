#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class WordDictionary {
    class Trie{
    public:
        bool isEnd;
        Trie* next[26];
        Trie(){
            isEnd = true;
            memset(next, 0, sizeof(next));
        }
    };
public:
    Trie* root;
    bool vaild;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
        vaild = true;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* node = root;
        for(auto const &ch : word){
            if(node[ch - 'a'] == nullptr){
                node[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Trie* node =

    }

    bool helper(string & word, int idx, Trie* node){
        if(idx >= word.size()){
            return node->isEnd;
        }
        for(int i = idx; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(node->next[j] != nullptr){
                        bool flag = helper(word, idx + 1, node->next[j]);
                        if(flag)
                            return true;
                    }
                }
            }else if(node->next[word[i] - 'a'] == nullptr){
                return false;
            }
            node = node->next[word[i] - 'a'];
        }
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */