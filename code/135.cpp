#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        int sum = 0;
        vector<int> ans(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1])
                ans[i] = ans[i - 1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                ans[i] = max(ans[i], ans[i + 1] + 1);
            sum += ans[i];
        }
        sum += ans.back();
        return sum;
    }
};