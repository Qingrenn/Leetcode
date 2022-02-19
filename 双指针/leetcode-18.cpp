class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        int cnt = 0, MOD = 1e9 + 7;
        for (int i = 0; i < staple.size(); i++) {
            int other = x - staple[i];
            if (other < 1)  break;
            int l = 0, r = drinks.size() - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (drinks[mid] > other)    r = mid - 1;
                else l = mid;
            } 
            if (drinks[l] <= other)
                cnt = (cnt + l + 1) % MOD;
        }

        return cnt;
    }
};

/*
这里双循环，时间复杂度o(nlogn)
如果使用双子针，时间复杂度可以降到o(n)
*/