#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class Solution {
public:
    typedef pair<int, int> P;
    struct myHash{
        size_t operator()(const P &x) const {
            return hash<size_t>()(hash<int>()(x.first) ^ hash<int>()(x.second));
        }
    };

    int gcd(int a, int b){
        if(b == 0) return a;
        else return gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<P, int, myHash> mp;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int delta_x = points[j][0] - points[i][0];
                int delta_y = points[j][1] - points[i][1];
                int g = gcd(delta_x, delta_y);
                if(g){
                    delta_x /= g;
                    delta_y /= g;
                }
                if(delta_x < 0 && delta_y > 0){
                    delta_x *= -1;
                    delta_y *= -1;
                }
                mp[P(delta_x, delta_y)]++;
            }
            int base = mp[P(0, 0)];
            ans = max(ans, base);
            for(const auto& item : mp){
                if(item.first == P(0, 0))
                    continue;
                ans = max(ans, item.second + base);
            }
            mp.clear();
        }
        return ans;
    }
};