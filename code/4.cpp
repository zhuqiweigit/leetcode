#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num = nums1.size() + nums2.size();
        int k = (nums1.size() + nums2.size()) / 2 + 1;
        if(num % 2 == 0)
            return (helper(nums1, nums2, 0, 0, k - 1) + helper(nums1, nums2, 0, 0, k)) / 2.0;
        else return helper(nums1, nums2, 0, 0, k);
    }

    int helper(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, int k){
        if(idx1 == nums1.size() || idx2 == nums2.size()){
            return idx1 == nums1.size() ? nums2[idx2 + k - 1] : nums1[idx1 + k - 1];
        }
        if(k == 1){
            return min(nums1[idx1], nums2[idx2]);
        }
        int mid = k / 2, l1 = mid, l2 = mid;
        if(idx1 + mid - 1 >= nums1.size()){
           l1 = nums1.size() - idx1;
        }
        if(idx2 + mid - 1 >= nums2.size()){
            l2 = nums2.size() - idx2;
        }
        if(nums1[idx1 + l1 - 1] < nums2[idx2 + l2 - 1]){
            return helper(nums1, nums2, idx1 + l1, idx2, k - l1);
        }else{
            return helper(nums1, nums2, idx1, idx2 + l2, k - l2);
        }
    }
};