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

class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA = 0, cntB = 0;
        map<char, int> mp;
        for(int i = 0; i < secret.size(); i++){
            if(mp.find(secret[i]) == mp.end()){
                mp[secret[i]] = 1;
            }else{
                mp[secret[i]]++;
            }
        }
        int j;
        for(j = 0; j < guess.size(); j++){
            if(j < secret.size() && guess[j] == secret[j])
                cntA++;
            if(mp.find(guess[j]) != mp.end() && mp[guess[j]] > 0){
                cntB++;
                mp[guess[j]]--;
            }
        }
        cntB = cntB - cntA;
        return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};