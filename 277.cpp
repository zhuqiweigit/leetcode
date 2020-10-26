#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        int cele = 0;
        for(int i = 1; i < n; i++){
            if(knows(cele, i)){
                cele = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(i == cele)
                continue;
            if(knows(cele, i) || !knows(i, cele))
                return -1;
        }
        return cele;
    }
};