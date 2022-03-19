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
    string tree2str(TreeNode* root) {
        if (root == nullptr)    return "";
        return dfs(root);
    }

    string dfs(TreeNode* node) {
        string ans = "";
        if (node->left != nullptr)
            ans = "(" + dfs(node->left) + ")";
        else if (node->right != nullptr)
            ans = "()";
        if (node->right != nullptr)
            ans += "(" + dfs(node->right) + ")";
        return to_string(node->val) + ans;
    }

};

/*
可以直接将tree2str方法写成递归
也可以尝试迭代法
*/