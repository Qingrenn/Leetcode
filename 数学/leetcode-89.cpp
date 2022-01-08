class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gc = {0};
        for (int i = 1; i <= n; i++) {
            int head = 1 << (i - 1);
            for (int j = gc.size() - 1; j >= 0; j--) {
                gc.push_back(gc[j] + head);
            }
        }
        return gc;
    }
};