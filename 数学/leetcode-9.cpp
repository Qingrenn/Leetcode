class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while (l < s.size()) {
            if (s[l] == s[r])   l++ ,r--;
            else return false;
        }
        return true;
    }
};