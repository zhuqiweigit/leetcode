#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hashTable;
        vector<int> stk(nums2.size()), ans(nums1.size());
        int ptr = -1;
        for(auto item : nums2){
            while(ptr != -1 && stk[ptr] < item){
                hashTable[stk[ptr]] = item;
                --ptr;
            }
            stk[++ptr] = item;
        }
        int index = -1;
        for(auto item : nums1){
            int temp = hashTable.count(item) ? hashTable[item] : -1;
            ans[++index] = temp;
        }
        return ans;
    }
};

int main(){
    vector<int> nums1{4,1,2}, nums2{1,3,4,2};
    Solution solution;
    solution.nextGreaterElement(nums1, nums2)
}