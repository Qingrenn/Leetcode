class Solution {
    int w;
    int h;
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        h = grid.size(), w = grid[0].size();
        for (int i = 0; i < w; i++) {
            int x = 0, y = i, z = 1, vx = 0, vy = 0;
            while ( x < h ){
                // cout << x << y << z << " ";
                vector<int> v = move(x, y, z, grid);
                int vx = v[0], vy = v[1];
                // cout << vx << vy << z << endl;
                if ( vx == 0 && vy == 0 )  break;
                x += vx, y += vy, z = v[2];
            }
            if (x == h) res.push_back(y);
            else res.push_back(-1);
            // cout << endl;
        }
        return res;
    }

    vector<int> move(int x, int y, int z, vector<vector<int>>& grid) {
        // z: 1 -> 板的上方 0 -> 板的下方
        int baffle = grid[x][y];
        vector<int> v;
        // baffle   z   baffle[x][y+1]   move
        // 1        1   1                vx=0 vy=1 z=0
        // 1        1.  -1               vx=0 vy=0 
        
        //              baffle[x+1][y]
        // 1        0.  1                vx=1 vy=0 z=1
        // 1        0.  -1               vx=1 vy=0 z=1

        // baffle   z   baffle[x][y-1]   move
        // -1       1   1                vx=0 vy=0
        // -1       1   -1               vx=0 vy=-1 z=0 
        
        //              baffle[x+1][y]
        // -1       0.  1                vx=1 vy=0 z=1
        // -1       0.  -1               vx=1 vy=0 z=1
        
        if (baffle == 1) {
            if (z == 1){
                if ( y + 1 < w && grid[x][y+1] == 1)  v = {0, 1, 0};
                else    v = {0, 0, -1};
            }else   v = {1, 0, 1};
        }else {
            if (z == 1) {
                if ( y - 1 < 0 || (y - 1 >=0 && grid[x][y-1] == 1) )  v = {0, 0, -1};
                else v = {0, -1, 0};
            }else   v = {1, 0, 1};
        }
        return v;
    }
};

/*
存在更好的模拟思路，这样打表不是很合适
*/