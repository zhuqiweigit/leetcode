#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int ll = 1, rr = n;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) > 0)
                ll = mid + 1;
            else rr = mid - 1;
        }
        return -1;
    }
};