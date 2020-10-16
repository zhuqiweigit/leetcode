#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        int cnt = 0;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        if(cnt == 0)
            return;
        helper(head, cnt);
    }

    ListNode* helper(ListNode* head, int n){
        if(n == 1){
            ListNode* subTail = head->next;
            head->next = nullptr;
            return subTail;
        }
        if(n == 2){
            ListNode* subTail = head->next->next;
            head->next->next = nullptr;
            return subTail;
        }

        ListNode* tail = helper(head->next, n - 2);
        ListNode* temp = head->next;
        ListNode* tailtail = tail->next;
        head->next = tail;
        tail->next = temp;
        return tailtail;
    }
};