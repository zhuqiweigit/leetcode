#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
private:
    class Node{
    public:
        int key, value;
        Node* pre, *next;
        Node():key(0), value(0), pre(nullptr), next(nullptr){}
        Node(int key, int value): key(key), value(value), pre(nullptr), next(nullptr){}
    };

    unordered_map<int, Node*> cache;
    Node* dummy_head, *dummy_tail;
    int capacity, size;

public:
    LRUCache(int capacity):capacity(capacity), size(0) {
        dummy_head = new Node();
        dummy_tail = new Node();
        dummy_head->next = dummy_tail;
        dummy_tail->pre = dummy_head;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            move_to_head(node);
            return node->value;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            move_to_head(node);
            return;
        }else{
            Node* node = new Node(key, value);
            insert_to_head(node);
            size++;
            if(size > capacity){
                size--;
                delete_tail();
            }
            return;
        }
    }

private:
    void move_to_head(Node* node){
        Node* pre = node->pre, *next = node->next;
        pre->next = next;
        next->pre = pre;
        insert_to_head(node);
    }

    void insert_to_head(Node* node){
        cache[node->key] = node;
        Node* dummy_next = dummy_head->next;
        dummy_head->next = node;
        node->pre = dummy_head;
        node->next = dummy_next;
        dummy_next->pre = node;
    }

    void delete_tail(){
        if(dummy_head->next == dummy_tail)
            return;
        Node* node = dummy_tail->pre;
        dummy_tail->pre = node->pre;
        node->pre->next = dummy_tail;
        cache.erase(node->key);
        delete node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */