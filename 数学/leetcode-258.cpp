class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = 0;
            while ( num >= 10) {
                tmp += num % 10;
                num /= 10;
            }
            tmp += num;
            num = tmp;
        }
        return num;
        
    }
};

/*
这里我用的是模拟
最好的方法是利用数学的方法
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/add-digits/solution/ge-wei-xiang-jia-by-leetcode-solution-u4kj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/