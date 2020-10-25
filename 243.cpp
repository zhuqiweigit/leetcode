#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1;
        int min_len = numeric_limits<int>::max();
        for(int idx = 0; idx < words.size(); idx++){
            if(words[idx] == word1){
                i = idx;
                if(j != -1) min_len = min(min_len, abs(j - i));
            }
            if(words[idx] == word2){
                j = idx;
                if(i != -1) min_len = min(min_len, abs(j - i));
            }
        }
        return min_len;
    }
};