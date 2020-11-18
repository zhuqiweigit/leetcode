#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string> num1 = {"","One", "Two", "Three", "Four", "Five", "Six",
                           "Seven", "Eight", "Nine", "Ten",
                           "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                           "Eighteen", "NineTeen", "Twenty"};
    vector<string> num2 = {"", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty",
                           "Ninety"};
    vector<string> num3 = {"Hundred", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string ans = helper(num);
        ans = ans.substr(1);
        return ans;
    }

    string helper(int num){
        if(num == 0) {
            return "";
        }
        if(num < 20) {
            return " " + num1[num];
        }
        if(num < 100){
            return " " + num2[num / 10] + helper(num % 10);
        }
        if(num < 1000){
            return " " + num1[num / 100] + " " + num3[0] + helper(num % 100);
        }
        for(int i = 1, fact = 1000 * 1000; i <= 3; i++, fact *= 1000){
            if(num < fact){
                return helper(num / (fact / 1000)) + " " + num3[i] + helper(num % (fact / 1000));
            }
        }
        return "";
    }
};