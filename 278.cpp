#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int ll = 0, rr = n - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(isBadVersion(mid)){
                rr = mid - 1;
            }else{
                ll = mid + 1;
            }
        }
        return ll;
    }
};