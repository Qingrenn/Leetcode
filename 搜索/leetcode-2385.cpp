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
    int res = 0;
    int dfs(TreeNode* root, int start, bool &flag) {
        if (root == nullptr)    return -1;
        bool lflag = false, rflag = false;
        int l = dfs(root->left, start, lflag) + 1;
        int r = dfs(root->right, start, rflag) + 1;
        if (lflag || rflag) {
            flag = true;
            res = max(res, l + r);
            if (lflag)
                return l;
            else
                return r;
        }
        if (root->val == start) {
            flag = true;
            res = max(l, r);
            return 0;
        }
        return max(l, r);
    }

    int amountOfTime(TreeNode* root, int start) {
        bool flag = false;
        dfs(root, start, flag);
        return res;
    }
};