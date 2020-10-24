#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0)
            return ans;
        vector<int> temp(1, 1);
        ans.push_back(temp);
        for(int i = 1; i < numRows; i++){
            vector<int> line(i + 1);
            for(int j = 0; j < i + 1; j++){
                if(j - 1 < 0){
                    line[j] = ans[i - 1][j];
                }else if(j >= i){
                    line[j] = ans[i - 1][j - 1];
                }else{
                    line[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
            ans.push_back(line);
        }
        return ans;
    }
};