class MyCalendarThree {
private:
    struct Node {
        int lc, rc, add, max;
    };
    const static int N = 1e9, M = 4 * 400 * 20;
    int cnt = 1;
    Node tr[M]={{0,0,0,0}};

    // update(1, 1, N+1, L, R, x)
    void update(int n, int l, int r, int L, int R, int x) {
        // 不同于一般线段树 在（l==r），即修改完叶子节点后退出。若当前区间是修改区间的子区间，那么打上懒标记
        if (L <= l && r <= R) {
            tr[n].add += x; tr[n].max += x;
            return;
        }
        lazycreate(n); // 如果要访问节点n的孩子节点，就需要创建其孩子节点
        pushdown(n); // 下放数据
        int m = l + r >> 1;
        if (L <= m) update(tr[n].lc, l, m, L, R, x);
        if (R > m)  update(tr[n].rc, m+1, r, L, R, x);
        pushup(n); // 从子节点更新当前节点数据
        return;
    }

    // query(1, 1, N+1, L, R)
    int query(int n, int l, int r, int L, int R) {
        if (L <= l && r <= R)   return tr[n].max;
        lazycreate(n);
        pushdown(n);
        int m = l + R >> 1, ans = 0;
        if (L <= m) ans = query(tr[n].lc, l, m, L, R);
        if (R > m)  ans = std::max(ans, query(tr[n].rc, m+1, r, L, R));
        return ans;
    }

    // 访问到第n个节点，创建其左右孩子
    void lazycreate(int n) {
        if (tr[n].lc == 0)
            tr[n].lc = ++cnt;
        if (tr[n].rc == 0)
            tr[n].rc = ++cnt;
        return;
    }

    // 访问到第n个节点时，下放数据
    void pushdown(int n) {
        tr[tr[n].lc].add += tr[n].add; tr[tr[n].lc].max += tr[n].add;
        tr[tr[n].rc].add += tr[n].add; tr[tr[n].rc].max += tr[n].add;
        tr[n].add = 0;
        return;
    }

    // 从子节点更新当前节点
    void pushup(int n) {
        tr[n].max = std::max(tr[tr[n].lc].max, tr[tr[n].rc].max);
        return;
    }

public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        update(1, 1, N+1, start+1, end, 1);
        return query(1, 1, N+1, 1, N+1);
    }
};

/**
 * @brief 
 * 带懒节点的线段树
 */