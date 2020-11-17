#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Vector2D {
public:
    vector<int> my_vactor;
    int ptr = 0;
    Vector2D(vector<vector<int>>& v) {
        for(const auto& vi : v){
            my_vactor.insert(my_vactor.end(), vi.begin(), vi.end());
        }
    }

    int next() {
        return my_vactor[ptr++];
    }

    bool hasNext() {
        return ptr < my_vactor.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */