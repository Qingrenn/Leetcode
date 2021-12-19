class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int height = board.size();
        const int width = board[0].size();

        int state[height][width];
        for (int i = 0; i < height; i++)
            memset(state[i], -1, sizeof state[i]);
        
        
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                if (board[r][c] == 'X' || state[r][c] != -1)
                    continue;
                
                queue<pair<int, int>> q;
                q.push({r, c});
                vector<pair<int,int>> path;
                path.push_back({r, c});
                bool surrounded = true;

                while (!q.empty()) {
                    pair<int, int> t = q.front();
                    path.push_back(t);
                    q.pop();
                    int x = t.first, y = t.second;
                    if (x == height - 1 || x == 0 || y == width -1 || y == 0)
                        surrounded = false;

                    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
                    for (int i = 0; i < 4; i++) {
                        int a = x + dx[i], b = y + dy[i];
                        if (a >= 0 && a < height && b >=0 && b < width && board[a][b] == 'O' && state[a][b] == -1) {
                            q.push({a, b});
                            state[a][b] = 0;
                        }
                    }
                }

                if (surrounded == true) {
                    for (pair<int, int> p : path)
                        board[p.first][p.second] = 'X';
                }
            }
        }

    }
};

/*
这里是用了BFS，用并查集应该更优。
*/