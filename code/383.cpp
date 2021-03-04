#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        for(int i = 0; i < magazine.size(); i++){
            if(mp.find(magazine[i]) == mp.end()){
                mp[magazine[i]] = 1;
            }else{
                mp[magazine[i]]++;
            }
        }
        for(int i = 0; i < ransomNote.size(); i++){
           if(mp.find(ransomNote[i]) == mp.end() ||
           mp[ransomNote[i]] <= 0)
               return false;
           mp[ransomNote[i]]--;
        }
        return true;
    }
};