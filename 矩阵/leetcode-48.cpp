class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i <= (n - 1 >> 1); i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int temp_x = j , temp_y = n - 1 - i;
                if (temp_x == i && temp_y == j)
                    continue;
                for (int k = 0; k < 3; k++) {
                    cout << temp_x << ", " << temp_y << endl;
                    swap(matrix[i][j], matrix[temp_x][temp_y]);
                    int backup_x = temp_x;
                    temp_x = temp_y, temp_y = n - 1 - backup_x;
                }
            }
        }
    }
};

/*
顺时针旋转的映射：(x，y) -> (y, n - 1 - x)
有更容易的思路，但是时间复杂度仍是o(n^2)。
*/