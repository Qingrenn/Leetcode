class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> char2int = {{'I', 1},
                                            {'V', 5},
                                            {'X', 10},
                                            {'L', 50},
                                            {'C', 100},
                                            {'D', 500},
                                            {'M', 1000}};
        int res = 0;
        int pre_value = 0;
        for (int i = s.length() - 1; i >=0 ; i--) {
            int value = char2int[s[i]];
            if ( value >= pre_value )
                res += value;
            else
                res -= value;
            pre_value = value;
        }
        return res;
    }
};

/*
主要在于挖掘罗马数字组合的关系，从右往左，一般规则从小到大排列。
个别情况出现小的数在大的数左边，出现做减法即可。
*/