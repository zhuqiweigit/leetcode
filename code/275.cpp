#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int Hidx = 0, ll = 0, rr = citations.size() - 1, mid;
        if(citations.size() == 0)
            return 0;
        while(ll <= rr){
            mid = ll + (rr - ll) / 2;
            if(citations[mid] == citations.size() - mid)
                return citations.size() - mid;
            else if(citations[mid] < citations.size() - mid)
                ll = mid + 1;
            else rr = mid - 1;
        }
        return citations.size() - ll + 1;
    }
};