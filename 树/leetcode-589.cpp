/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        // recurse(root, res);
        if (root == nullptr)    return res;
        stack<Node*> s;
        s.push(root);
        while ( !s.empty() ) {
            Node* t = s.top();
            s.pop();
            res.push_back(t->val);
            for (auto it = t->children.rbegin(); it != t->children.rend(); it++)
                s.push(*it);
        }
        return res;
    }

    // void recurse(Node* node, vector<int> &res) {
    //     if ( node == nullptr )  return;
    //     res.push_back(node->val);
    //     for (Node* c : node->children) {
    //         recurse(c, res);
    //     }
    //     return;
    // }


};