#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        dfs(n, n, path);
        return ans;
    }

    void dfs(int n, int num, vector<int>& path){
        if(num != n) {
            path.push_back(num);
            ans.push_back(path);
            path.pop_back();
        }
        if(isPrime(num)){
            return;
        }
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i != 0) continue;
            path.push_back(i);
            dfs(n, num / i, path);
            path.pop_back();
        }
    }

    bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2)
            return true;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
};