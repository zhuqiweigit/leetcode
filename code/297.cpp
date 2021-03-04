#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        my_serialize(root, os);
        return os.str();
    }

    void my_serialize(TreeNode* root, ostringstream& os){
        if(root == nullptr){
            os << "# ";
            return;
        }else{
            os << to_string(root->val) << " ";
            my_serialize(root->left, os);
            my_serialize(root->right, os);
            return;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return my_deserialize(is);
    }

    TreeNode* my_deserialize(istringstream& is){
        string node_str;
        is >> node_str;
        if(node_str == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(node_str));
        root->left = my_deserialize( is);
        root->right = my_deserialize(is);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));