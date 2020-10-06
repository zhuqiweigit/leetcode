#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};


class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(node->right){
            Node* temp = node->right;
            while(temp->left){
                temp = temp->left;
            }
            return temp;
        }else{
            if(node->parent && node == node->parent->left){
                return node->parent;
            }else{
                Node* temp = node;
                while(temp->parent && temp == temp->parent->right){
                    temp = temp->parent;
                }
                if(temp->parent == nullptr)
                    return nullptr;
                else if(temp == temp->parent->left)
                    return temp->parent;
                else return nullptr;
            }
        }
    }
};