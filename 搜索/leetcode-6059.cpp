class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        bool state[m][n][(m+n+1)/2+1]; memset(state, 0, sizeof state);
        function<bool(int, int, int)> dfs = [&] (int x, int y, int c) -> bool {
            c += (grid[x][y] == '(') ? 1 : -1;
            if (c < 0)  return false;
            if ( c > m - x + n - y )    return false;
            if ( x == m -1 && y == n -1 )   return c == 0;
            if (state[x][y][c]) return false;
            
            state[x][y][c] = true;
            return (x+1<m && dfs(x+1,y,c)) || (y+1<n && dfs(x,y+1,c));
        };
        return dfs(0,0,0);
    }
};

/*
确定搜索过程中每个节点的状态，避免重复搜索。
*/