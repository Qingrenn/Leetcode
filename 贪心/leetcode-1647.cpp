class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        int bucket[26] = {0};
        for (char c : s)    bucket[c-'a']++;
        sort(bucket, bucket+26);
        for (int i = 24; i>= 0; i--) {
            if (bucket[i] >= bucket[i+1] && bucket[i]!=0) {
                int tmp = bucket[i];
                bucket[i] = (bucket[i+1] == 0) ? 0 : bucket[i+1] - 1;
                res += tmp - bucket[i];
            }
        }
        return res;
    }
};

/*
贪心：计数+排序
*/