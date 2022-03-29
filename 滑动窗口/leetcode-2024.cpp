class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getLongestWin(answerKey, k, 'T'), getLongestWin(answerKey, k, 'F'));
    }

    int getLongestWin(string &answerKey, int k, char c) {
        int cNum = 0, maxL = 0;
        for (int r = 0, l = 0; r < answerKey.length(); r++) {
            if (answerKey[r] == c)  cNum++;
            while (cNum > k){
                if (answerKey[l++] == c)    cNum--;
            }               
            maxL = max(maxL, r - l + 1);
        }
        return maxL;
    }
};


/*
滑动窗口维护一个修改元素不大于k的窗口，最大长度的窗口即为修改后的最长字符串。
*/