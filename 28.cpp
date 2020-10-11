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
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int i = 0, j = 0, curLen = 0;
        int Nlen = needle.size(), Hlen = haystack.size();
        while(i < Nlen && j < Hlen - Nlen + 1){
            while(j < Hlen - Nlen + 1 && i < Nlen && haystack[j] != needle[i])  j++;
            while(j < Hlen && i < Nlen && haystack[j] == needle[i]){
                i++;
                j++;
                curLen++;
            }
            if(curLen == Nlen){
                return j - curLen;
            }else{
                j = j - curLen + 1;
                curLen = 0;
                i = 0;
            }
        }
        return -1;
    }
};