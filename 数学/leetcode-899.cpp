class Solution {
public:
    string orderlyQueue(string s, int k) {
        int length = s.size();
        string tmp = s + s;
        string res = s;
        if (k == 1)
            for (int i = 0; i < length; i++)
                res = min(res, tmp.substr(i, length));
        else
            sort(res.begin(), res.end());
        return res;
    }
};

/*
这道题是脑筋急转弯：
K = 1的时候，最小字符串就是通过循环位移可以得到的字符串
K >= 2的时候，可以通过这种操作得到所有可能的字符串组合，所以直接进行排序即可
*/