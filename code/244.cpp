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

class WordDistance {
public:
    map<string, vector<int>> mp;
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            if(mp.find(words[i]) == mp.end()){
                vector<int> temp;
                temp.push_back(i);
                mp[words[i]] = temp;
            }else{
                mp[words[i]].push_back(i);
            }
        }
    }

    int shortest(string word1, string word2) {
        vector<int> &loc1 = mp[word1], &loc2 = mp[word2];
        int i = 0, j = 0, min_dst = numeric_limits<int>::max();
        while(i < loc1.size() && j < loc2.size()){
            if(abs(loc1[i] - loc2[j]) < min_dst){
                min_dst = abs(loc1[i] - loc2[j]);
            }
            if(loc1[i] < loc2[j])
                i++;
            else j++;
        }
        return min_dst;
    }
};