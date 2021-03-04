#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > E){
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }
        int overlap;
        if(F >= D || H >= B || E >= C)
            overlap = 0;
        else{
            int ud = min(D, H) - max(B, F);
            int lr = min(C, G) - max(E, A);
            overlap = ud * lr;
        }
        int sum = (D - B) * (C - A) + (G - E) * (H - F) + overlap;
        return sum;
    }
};