#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        while(headA){
            st.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(st.find(headB) != st.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};