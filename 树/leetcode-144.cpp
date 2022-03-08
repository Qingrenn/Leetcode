/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)    return res;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if ( cur->right != nullptr ) s.push(cur->right);
            if ( cur->left != nullptr ) s.push(cur->left);
        }
        return res;
    }
};

/*
二叉树的先序遍历，使用栈进行迭代。
中序遍历，后序遍历都可以使用栈来进行迭代。
*/