class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;

        for (int i = 0; i < n; i++) {
            int len = min(m, n - i);
            res = max(res, maxLength(nums1, nums2, i, 0, len));
        }

        for (int i = 0; i < m; i++) {
            int len = min(n, m - i);
            res = max(res, maxLength(nums1, nums2, 0, i, len));
        }

        return res;
    }

    int maxLength(vector<int>& nums1, vector<int>& nums2, int addA, int addB, int len) {
        int res = 0, k = 0;
        for (int i = 0; i < len; i++) {
            if (nums1[addA + i] == nums2[addB + i])
                k++;
            else
                k = 0;
            res = max(k, res);
        }
        return res;
    }

};

/*
这里使用的是滑动窗口的方式进行的匹配，也可以使用二分+hash。这道题很精彩，需要扩展它的解法！
*/