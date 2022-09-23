class Solution {
public:
    int res = 0;
    int m;
    int n;
    int maximumRows(vector<vector<int>>& mat, int cols) {
        m = mat.size();
        n = mat[0].size();
        int cnt = 0;
        unordered_set<int> selected;
        dfs(cnt, cols, selected, mat);
        return res;
    }

    void dfs(int cnt, int cols, unordered_set<int>& selected, vector<vector<int>>& mat) {
        if (cnt == n || selected.size() == cols) {
            int row_num = 0;
            for (int i = 0; i < m; i++) {
                bool flag = false;
                for (int j = 0; j < n; j++) {
                    if (selected.count(j))  continue;
                    if (mat[i][j] == 1) flag = true;
                }
                if (!flag)   row_num++;
            }
            res = max(res, row_num);
            return;
        }

        dfs(cnt+1, cols, selected, mat);
        selected.emplace(cnt);
        dfs(cnt+1, cols, selected, mat);
        selected.erase(cnt);

        return;
    }
};