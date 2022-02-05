class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int h = grid.size();
        int w = grid[0].size();
        const int N = h * w;
        int u[N];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                u[i * w + j] = i * w + j;
                if ( grid[i][j] == '1' )   res++;
            }

        int dh[4] = {-1, 0, 0, 1};
        int dw[4] = {0, -1, 1, 0};

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] != '1')  continue;
                grid[i][j] = '0';
                for (int d = 0; d < 4; d++)
                {
                    int x = i + dh[d], y = j + dw[d];
                    if ( x >= 0 && y >= 0 && x < h && y < w &&  grid[x][y] == '1' )
                    {
                        int a = find(x * w + y, u), b = find(i * w + j, u);
                        if (a != b)
                        {
                            u[a] = b;
                            res--;
                        }
                    }
                }
            }
                    
        return res;
    }

    int find(int x, int s[])
    {
        if (s[x] != x) s[x] = find(s[x], s);
        return s[x];
    }
};

/*
这里是用并查集做的，也可以用DFS，BFS。时间复杂度都是o(WH)
并查集除了路径优化外，还可以使用秩优化。
*/