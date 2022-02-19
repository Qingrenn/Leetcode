class Solution {
public:
    int N, K;
    int vx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int vy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    double mem[110][30][30] = {0}; // cnt, r, c
    
    double knightProbability(int n, int k, int row, int column) {
        N = n, K = k;    
        return dfs(0, row, column);
    }

    double dfs(int cnt, int row, int column) {
        if ( column > N - 1 || column < 0 || row > N - 1 || row < 0 ) return 0;
        if ( cnt == K )
            return 1;
        if (mem[cnt][row][column])
            return mem[cnt][row][column];

        double prob = 0;
        for (int i = 0; i < 8; i++) {
            int x = row + vx[i], y = column + vy[i];
            prob += (dfs(cnt + 1, x, y) / 8.0);
        }

        mem[cnt][row][column] = prob;

        return prob;
    }
};

/*
可以尝试用动态规划解。
但是我在这里使用的是暴力搜索，通过记忆化剪枝。
*/