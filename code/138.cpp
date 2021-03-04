#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
       Node* dummy = new Node(0), *cur = dummy, *dummy_origin = new Node(0),
       *cur_origin = dummy_origin;
       dummy_origin->next = head;
       mp[nullptr] = nullptr;
       while(cur_origin->next){
           Node* temp;
           if(mp.find(cur_origin->next) == mp.end()){
               temp = new Node(cur_origin->next->val);
               mp[cur_origin->next] = temp;
           }else{
               temp = mp[cur_origin->next];
           }
           if( mp.find(cur_origin->next->next) == mp.end()){
               temp->next = cur_origin->next->next == nullptr ? nullptr : new Node(cur_origin->next->next->val);
               mp[cur_origin->next->next] = temp->next;
           }else{
               temp->next = mp[cur_origin->next->next];
           }
           if(mp.find(cur_origin->next->random) == mp.end()){
               temp->random = cur_origin->next->random == nullptr ? nullptr : new Node(cur_origin->next->random->val);
               mp[cur_origin->next->random] = temp->random;
           }else{
               temp->random = mp[cur_origin->next->random];
           }
           cur->next = temp;
           cur = cur->next;
           cur_origin = cur_origin->next;
       }
        return dummy->next;
    }
};