class Solution {
public:
    int countPrimes(int n) {
        // int res = 0;
        // for (int i = 2; i < n; i++) {
        //     res += isPrime(i);
        // }
        // return res;
       
        int res = 0;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                if ((long long)i * i < n) {
                    for (int j = i; j * i < n; j += 1) {
                        isPrime[j * i] = 0;
                    }
                }
            }
        }
        return res;
    }

    // bool isPrime(int x) {
    //     for (int i = 2; i * i <= x; i++) {
    //         if ( x % i == 0 )
    //             return false;
    //     }
    //     return true;
    // }
};

/*
尝试了暴力和埃氏法，还有线性筛。
*/