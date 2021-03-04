#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class ValidWordAbbr {
public:
    map<string, set<string>> mp;
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            if(dictionary[i].size() == 2){
                mp[dictionary[i]].insert(dictionary[i]);
            }else{
                string temp;
                temp = temp + dictionary[i][0] + to_string(dictionary[i].size()  -2) + dictionary[i][dictionary[i].size() - 1];
                mp[temp].insert(dictionary[i]);
            }
        }
    }

    bool isUnique(string word) {
        string temp = word;
        if(word.length() > 2){
            word = word[0] + to_string(word.length() - 2) + word[word.size() - 1];
        }
        if(mp.find(word) == mp.end() || mp[word].find(temp) != mp[word].end() && mp[word].size() == 1){
            return true;
        }
        return false;

    }
};
