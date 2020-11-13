#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class Trie {
public:
    bool isEnd;
    Trie* next[26];
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, nullptr, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(const auto& ch : word){
            if(node->next[ch - 'a'] == nullptr){
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(const auto & ch : word){
            if(node->next[ch - 'a'] == nullptr){
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = this;
        for(auto const & ch : prefix){
            if(node->next[ch - 'a'] == nullptr)
                return false;
            node = node->next[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */