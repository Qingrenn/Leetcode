class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        splitPlural(num1, a1, b1);
        splitPlural(num2, a2, b2);
        int real = a1 * a2 - b1 * b2;
        int noun = a1 * b2 + a2 * b1;
        return to_string(real) + '+' + to_string(noun) + 'i';
    }

    void splitPlural(string num, int &a, int &b) {
        int sep = num.find_first_of('+', 1);
        string real = num.substr(0, sep);
        string noun = num.substr(sep+1, num.length()-sep-1);
        a = str2Num(real);
        b = str2Num(noun);
    }

    int str2Num(string num) {
        int flag = 1, res = 0;
        if (num[0] == '-') flag = -1;
        for (int i = 0; i < num.length(); i++)
            if ( num[i] >= '0' && num[i] <= '9' )
                res = res * 10 + num[i] - '0';
        return flag * res;
    }

};

/*
这样分割字符串并不是很合适，有如下解决方法：
1.输入流 stringstream
2. 正则表达式 （学会正则还是很重要的）
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};
*/