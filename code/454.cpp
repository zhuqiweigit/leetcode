#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> ans1, ans2;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                ans1.push_back(A[i] + B[j]);
            }
        }
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                ans2.push_back(C[i] + D[j]);
            }
        }
        int cnt = 0;
        for(int i = 0; i < ans1.size(); i++){
            for(int j = 0; j < ans2.size(); j++){
                if(ans1[i] + ans2[j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};