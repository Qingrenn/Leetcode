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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        // recurse(root, res);

        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* n = s.top();
            s.pop();
            res.push_back(n->val);
            for (auto it = n->children.begin(); it != n->children.end(); it++)
                s.push(*it);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // void recurse(Node* node, vector<int> &res) {
    //     for (Node* c : node->children)
    //         recurse(c, res);
    //     res.push_back(node->val);
    // }
};

/*
后序的reverse 是 中->右->左
先序 是 中->左->右
所以只要按照先序遍历的模式，先让左孩子入栈，得到遍历结果，然后再reverse即可。
*/