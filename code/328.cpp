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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd,*odd_head, *even, *even_head;
        if(head == nullptr || head->next == nullptr)
            return head;
        odd = odd_head = head;
        even = even_head = head->next;
        ListNode* cur = head->next->next;
        while(cur){
            odd->next = cur;
            cur = cur->next;
            odd = odd->next;
            odd->next = nullptr;
            if(cur == nullptr)
                break;
            even->next = cur;
            cur = cur->next;
            even = even->next;
            even->next = nullptr;
        }
        odd->next = nullptr;
        even->next = nullptr;
        odd->next = even_head;
        return odd_head;
    }
};