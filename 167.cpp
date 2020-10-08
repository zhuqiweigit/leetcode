#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++){
            int a = numbers[i];
            int idx = binSearch(numbers, i + 1, numbers.size() - 1, target - a);
            if(idx != -1){
                ans.push_back(i + 1);
                ans.push_back(idx + 1);
                return ans;
            }
        }
        return ans;
    }

    vector<int> twoSum2(vector<int>& numbers, int target){
        int i = 0,j = numbers.size() - 1;
        vector<int> ans;
        while(i < j){
            if(numbers[i] + numbers[j] < target)
                i++;
            else if(numbers[i] + numbers[j] > target)
                j--;
            else{
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        return ans;
    }
private:
    int binSearch(vector<int>&numbers, int ll, int rr, int target){
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(numbers[mid] < target)
                ll = mid + 1;
            else if(numbers[mid] > target)
                rr = mid - 1;
            else return mid;
        }
        return -1;
    }
};