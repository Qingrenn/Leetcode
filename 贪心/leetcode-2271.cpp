class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        
        vector<int> presum;
        vector<int> rightBounds;
        int prefix = 0;
        presum.push_back(prefix);
        for (auto t : tiles) {
            prefix += t[1] - t[0] + 1;
            presum.push_back(prefix);
            rightBounds.push_back(t[1]);
        }

        int num = 0;
        for (int i = 0; i < tiles.size(); i++) {
            int l = tiles[i][0], r = l + carpetLen - 1;
            int j = lower_bound(rightBounds.begin(), rightBounds.end(), r) - rightBounds.begin();
            
            int cnt = presum[j] - presum[i];
            if (j < tiles.size() && r >= tiles[j][0])   cnt += r - tiles[j][0] + 1;
            // cout << j << " " << cnt << endl;
            num = max(num, cnt);
            
        }
        return num;

    }
};

/**
 * @brief 
 * 贪心确定遍历的方式，使用前缀和和二分查找来处理离散区间。
 */
