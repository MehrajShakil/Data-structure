///1. Merge left and right
int combine (int left, int right) {
    return left + right;
}
 
///2. Push lazy down and merge lazy
void propagate(int u, int st, int en) {
    if (lz[u] == -1) return;
    tr[u] = (en-st+1)*lz[u];
    if (st!=en) {
        lz[2*u] = lz[u];
        lz[2*u+1] = lz[u];
    }
    lz[u] = -1;
}
 
 
void build(int u, int st, int en) {
    if (st==en) {
        tr[u] = a[st];          ///3. Initialize
        lz[u] = -1;
    }
    else {
        int mid = (st+en)/2;
        build(2*u, st, mid);
        build(2*u+1, mid+1, en);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
        lz[u] = -1;              ///3. Initialize
    }
}
 
void update(int u, int st, int en, int l, int r, int x) {
    propagate(u, st, en);
    if (r<st || en<l)  return;
    else if (l<=st && en<=r) {
        lz[u] = x;             ///4. Merge lazy
        propagate(u, st, en);
    }
    else {
        int mid = (st+en)/2;
        update(2*u, st, mid, l, r, x);
        update(2*u+1, mid+1, en, l, r, x);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
    }
}
 
int query(int u, int st, int en, int l, int r) {
    propagate(u, st, en);
    if (r<st || en<l)  return 0;        /// 5. Proper null value
    else if (l<=st && en<=r)    return tr[u];
    else {
        int mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}
