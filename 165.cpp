#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream is1(version1), is2(version2);
        string s1, s2;
        vector<int> v1, v2;
        while(getline(is1, s1, '.')){
            v1.push_back(stoi(s1));
        }
        while(getline(is2, s2, '.')){
            v2.push_back(stoi(s2));
        }
        int i;
        for(i = 0; i < v1.size() && i < v2.size(); i++){
            if(v1[i] > v2[i])
                return 1;
            if(v1[i] < v2[i])
                return -1;
        }
        while(i < v1.size()){
            if(v1[i++] > 0)
                return 1;
        }
        while(i < v2.size()){
            if(v2[i++] > 0)
                return -1;
        }
        return 0;
    }
};