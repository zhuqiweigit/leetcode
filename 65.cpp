#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int ll = 0, rr = s.size() - 1;
        while(ll < s.size() && s[ll] == ' ') ll++;
        while(rr >= 0 && s[rr] == ' ') rr--;
        if(ll > rr)
            return false;
        if(s[ll] == '+' || s[ll] == '-')
            ll++;
        string ss = s.substr(ll, rr - ll + 1);
        int epos = -1, point_pos = -1;
        for(int i = 0; i < ss.size(); i++){
            if(ss[i] == 'e') epos = i;
            if(ss[i] == '.') point_pos = i;
        }
        if(epos != -1){
            string ss1 = ss.substr(0, epos);
            string ss2 = ss.substr(epos + 1, ss.size() - epos);
            if(ss1[0] == '+' || ss1[0] == '-'){
                ss1 = ss1.substr(1, ss1.size() - 1);
            }
            if(ss2[0] == '+' || ss2[0] == '-')
                ss2 = ss2.substr(1, ss2.size() - 1);
            if(ss1.empty() || ss2.empty())
                return false;
            if(point_pos != -1){
                if(point_pos > epos)
                    return false;
                return checkFloat(ss1) && checkInt(ss2);
            }else{
                return checkInt(ss1) && checkInt(ss2);
            }
        }else{
            if(point_pos == -1){
                return checkInt(ss);
            }else{
                return checkFloat(ss);
            }
        }

    }

    bool checkInt(string s){
        for(int i = 0; i < s.size(); i++){
            if((s[i] < '0' || s[i] > '9'))
                return false;
        }
        return true;
    }

    bool checkFloat(string s){
        int point = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                point = i;
                break;
            }
        }
        if(point == -1)
            return false;
        string s1 = s.substr(0, point);
        string s2 = s.substr(point + 1, s.size());
        if(s1.empty() && s2.empty())
            return false;
        return checkInt(s1) && checkInt(s2);
    }
};