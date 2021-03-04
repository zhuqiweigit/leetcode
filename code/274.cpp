#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        int n = citations.size();
        vector<int> bucket(n + 1, 0);
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= n)
                bucket[n]++;
            else bucket[citations[i]]++;
        }
        int Hidx = n;
        for(int count = 0; count < Hidx; Hidx--){
            count += bucket[Hidx];
            if(count >= Hidx)
                break;
        }
        return Hidx;
    }
};