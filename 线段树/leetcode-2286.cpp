class BookMyShow {
private:
    int _n;
    int _m;
    long long *tr;
    int *_min;

    // add(1, 1, _n, idx, val);
    // o(logn)
    void add (int o, int l, int r, int idx, int val) {
        if (l == r) {
            tr[o] += val;
            _min[o] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            add(2*o, l, mid, idx, val);
        else
            add(2*o+1, mid+1, r, idx, val);
        tr[o] = tr[2*o] + tr[2*o+1];
        _min[o] = min(_min[2*o], _min[2*o+1]);
    }

    // query_sum(1, 1, 1, L, R);
    // o(logn)
    long long query_sum(int o, int l , int r, int L, int R) {
        if (L <= l && r <= R)
            return tr[o];
        long long sum = 0;
        int mid = l + r >> 1;
        if (L <= mid)
            sum += query_sum(2*o, l, mid, L, R);
        if (R > mid)
            sum += query_sum(2*o+1, mid+1, r, L, R);
        return sum;
    }

    int min_index(int o, int l ,int r, int R, int val) {
        if (_min[o] > val)
            return 0;
        if (l == r)
            return l;
        int mid = l + r >> 1;
        if (_min[2*o] <= val)
            return min_index(2*o, l, mid, R, val);
        if (mid < R)
            return min_index(2*o+1, mid+1, r, R, val);
        return 0;
    }

public:
    BookMyShow(int n, int m) {
        _n = n;
        _m = m;
        tr = (long long *) malloc(sizeof(long long) * 4 * n);
        _min = (int *) malloc(sizeof(int) * 4 * n);
        memset(tr, 0, sizeof(long long) * 4 * n);
        memset(_min, 0, sizeof(int) * 4 * n);
    }
    
    vector<int> gather(int k, int maxRow) {
        int min_row = min_index(1, 1, _n, maxRow+1, _m-k);
        if (min_row == 0)   return {};
        int seats = query_sum(1, 1, _n, min_row, min_row);
        add(1, 1, _n, min_row, k);
        return {min_row-1, seats};
    }
    
    bool scatter(int k, int maxRow) {
        if ((long long) _m * (maxRow+1) < query_sum(1, 1, _n, 1, maxRow+1) + k)
            return false;
        int row = min_index(1, 1, _n, maxRow+1, _m-1);
        while (true) {
            int left_seats = _m - query_sum(1, 1, _n, row, row);
            if (left_seats >= k) {
                add(1, 1, _n, row, k);
                return true;
            }
            k -= left_seats;
            add(1, 1, _n, row, left_seats);
            row+=1;
        }
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

/**
 * @brief 
 * 线段树: https://oi-wiki.org/ds/seg/
 */