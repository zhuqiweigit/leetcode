#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for(auto c : S){
            if(ans.size() != 0 && ans.back() == c){
                ans.pop_back();
            }else{
                ans += c;
            }
        }
        return ans;
    }
};



int main(){
    string S = "abbaca";
    Solution solution;
    cout << solution.removeDuplicates(S);
    return 0;
}