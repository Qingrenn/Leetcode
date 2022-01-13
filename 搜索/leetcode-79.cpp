class Solution {
int r, c;
public:
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size(), c = board[0].size();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool state[7][7];
                memset(state, false, sizeof state);
                state[i][j] = true;
                if (dfs(board, word, {i, j}, state, 0))   return true;
                // cout << endl;
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>> & board, string word, pair<int, int> pos, bool state[7][7], int cnt) {
        // cout << " [" << cnt << "] (" << pos.first << "," << pos.second << ") >>";
        if (cnt >= word.length() || word[cnt] != board[pos.first][pos.second])  return false;
        if (cnt == word.length() - 1)   return true;
        
        int vx[4] = {0, 0, 1, -1}, vy[4] = {1, -1, 0, 0};
        for (int j = 0; j < 4; j++) {
            int x = pos.first + vx[j], y = pos.second + vy[j];
            if ( (x>=0 && x<r) && (y>=0 && y<c) && !state[x][y]) {
                state[x][y] = true;
                if (dfs(board, word, {x, y}, state, cnt+1)) return true;
                state[x][y] = false;
            }

        }
        return false;
    }

};

/*
结点访问状态恢复现场
*/