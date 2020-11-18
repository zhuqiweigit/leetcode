#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class ZigzagIterator {
public:
    int ptr;
    vector<vector<int>> pool;
    vector<int> idx;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        pool.push_back(v1);
        pool.push_back(v2);
        for(const auto& v : pool){
            idx.push_back(0);
        }
        idx = 0;
    }

    int next() {
        for(int cnt = 0; cnt < pool.size(); cnt++){
            if(idx[ptr] < pool[ptr].size()) {
                int item = pool[ptr][idx[ptr]];
                idx[ptr]++;
                ptr++;
                ptr = ptr % pool.size();
                return item;
            }
        }
        return -1;
    }

    bool hasNext() {
        for(int cnt = 0; cnt < pool.size(); cnt++){
            int mod = pool.size();
            if(idx[(ptr + cnt) % mod] < pool[(ptr + cnt) % mod].size())
                return true;
        }
        return false;
    }
};