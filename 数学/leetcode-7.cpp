class Solution {
public:
    int reverse(int x) {
        string INT_MAX_STIRNG = to_string(INT_MAX);
        string INT_MIN_STRING = to_string(INT_MIN);
        INT_MIN_STRING = INT_MIN_STRING.substr(1, INT_MIN_STRING.length() - 1);
        string num = to_string(x);
        
        if (x < 0) 
            num = num.substr(1, num.length() - 1);

        int l = 0, r = num.size() - 1;
        while ( l < r ) swap(num[l++] ,num[r--]);
        
        if (num.length() == INT_MIN_STRING.length()) {
            if (x < 0) {
                if ( num > INT_MIN_STRING ) return 0;
                if ( num == INT_MIN_STRING ) return INT_MIN;
            }else
                if ( num > INT_MAX_STIRNG)  return 0;
        }

        if ( x < 0) return -1 * stoi(num.c_str());
        else return stoi(num.c_str());
        
    }
};

/*
可以基于数学知识，通过取余的方法取最小位数进行反转。

如果转成字符串进行翻转，在判断是否溢出的时候可以通过字符串比较的方式来判断。
*/