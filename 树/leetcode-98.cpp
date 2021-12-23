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

struct state {
    int min;
    int max;
    bool ISBST=true;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root).ISBST;
    }

    state dfs(TreeNode* root) {
        state cur;
        bool left_state = true, right_state = true;

        if (root->left != nullptr) {
            state left = dfs(root->left);
            left_state = left.ISBST && (root->val > left.max);
            cur.min = left.min;
        }else 
            cur.min = root->val;

        if (root->right != nullptr) {
            state right = dfs(root->right);
            right_state = right.ISBST && (root->val < right.min);
            cur.max = right.max;
        }else 
            cur.max = root->val;
        
        cur.ISBST = left_state && right_state;
        
        return cur;
    }
};