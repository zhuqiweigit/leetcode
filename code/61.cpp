#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* pt = head, *temp = head;
        if(head == nullptr)
            return nullptr;
        int cnt = 1;
        while(pt && pt->next){
            pt = pt->next;
            cnt++;
        }
        pt->next = head;
        k = k % cnt;
        for(int i = 0; i < (cnt - k - 1); i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};