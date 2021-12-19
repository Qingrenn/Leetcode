class Solution {
public:
    int myAtoi(string s) {
        // 去掉前导空格
        int length = s.length();
        if (length == 0)
            return 0;
        int start_idx = s.find_first_not_of(' ');
        if (start_idx == string::npos)
            return 0;
        // 检查符号
        int symbol = 1;
        if (s[start_idx] == '+' || s[start_idx] == '-') {
            if (s[start_idx] == '-')
                symbol = -1;
            start_idx++;
        }

        int num = 0;
        for (int i = start_idx; i < s.length(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                // 判断溢出 num = num * 10 + s[i] - 48;
                int num10 = 0;
                if ( INT_MAX / 10 >= num)    num10 = num * 10;
                else if ( symbol == -1 )
                    return INT_MIN;
                else 
                    return INT_MAX;

                if ( INT_MAX -  num10 > ( s[i] - 48 ) )
                    num = num10 - 48 + s[i];
                else if ( symbol == 1 )
                    return INT_MAX;
                else if ( symbol == -1 ) {
                    if ( INT_MAX - num10 <= ( s[i] - 48 ) - 1 )
                        return INT_MIN;
                    else
                        num = INT_MAX;
                }
            }
            else break;
        }

        return num * symbol;
    }
};

/*
这种思路，边界条件思考太复杂，也容易出错。
*/