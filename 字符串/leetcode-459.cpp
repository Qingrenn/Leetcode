class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        //return (s + s).find(s, 1) != s.size();
        
        const int length = s.length();
        int ne[length];
        ne[0] = -1;
        // 初始化ne数组
        for (int i = 1, j = -1; i < length; i++) {
            while ( j != -1 && s[i] != s[j + 1])    j = ne[j];
            if (s[i] == s[j+1]) j++;
            ne[i] = j;
        }

        string S = (s + s).substr(1, 2*length - 2);
        for (int i = 0, j = -1; i < 2*length - 2; i++) {
            while ( j != -1 && S[i] != s[j + 1])    j = ne[j];
            if ( S[i] == s[j + 1]) j++;
            if (j == length - 1) {
                return true;
            }
        }

        return false;

    }

};

/*
参考题解：https://leetcode-cn.com/problems/repeated-substring-pattern/solution/jian-dan-ming-liao-guan-yu-javaliang-xing-dai-ma-s/
*/