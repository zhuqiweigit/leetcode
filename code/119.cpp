#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex, 1);
        for(int i = 1; i <= rowIndex; i++){
            //i + 1行
            int pre = 0;
            for(int j = 0; j < i + 1; j++){
                if(j - 1 < 0){
                    ans[j] = ans[j];
                    pre = ans[j];
                }else if(j >= i){
                    ans[j] = pre;
                }else{
                    int temp = ans[j];
                    ans[j] = pre + ans[j];
                    pre = temp;
                }
            }
        }
        return ans;
    }
};