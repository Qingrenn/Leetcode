class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool res = true;
        int length = data.size();
        if (length == 0) return false;
        int i = 0;
        while (i < length){
            int skip = check(i, data);
            if (skip == -1)
                return false;
            i += skip;
        }

        return res;
    }

    int check(int i, vector<int>& data) {
        int num = data[i];
        if (num >> 7 == 0)  return 1;
        int nBytes = 2, tmp = num >> (7 - nBytes), pattern = 6;
        while (tmp != pattern) {
            nBytes++;
            if ( nBytes > 4)  return -1;
            pattern += (1 << nBytes);
            tmp = num >> ( 7 - nBytes);
        }
        // cout << nBytes << endl;
        if (i + nBytes - 1 > data.size() - 1)   return -1;
        for (int j = 1; j < nBytes; j++) {
            num = data[i + j];
            if (num >> 6 != 2)  return -1;
        }
        return nBytes;
    }


};
