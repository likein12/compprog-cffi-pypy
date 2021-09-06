typedef int64_t data_t;

typedef struct {
    int n;
    int depth;
    data_t *segtree;
    data_t (*op)(data_t, data_t);
    data_t ide;
} SegmentTree;

SegmentTree* SegmentTreeInit(data_t *array, int _length, data_t (*op)(data_t, data_t), data_t ide) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    int n = 1;
    int depth = 1;
    while (n<_length) {
        n*=2;
        depth++;
    }
    (*st).n = n;
    (*st).depth = depth;
    (*st).op = op;
    (*st).ide = ide;
    (*st).segtree = (data_t*)malloc((2*n-1)*sizeof(data_t));
    data_t* segtree = (*st).segtree;
    for (int i=n-1;i<2*n-1;++i) {
        if (n-1<=i && i<n-1+_length) segtree[i] = array[i-n+1];
        else segtree[i] = ide;
    }
    for (int i=n-2;i>=0;--i) segtree[i] = op(segtree[i*2+1],segtree[i*2+2]);
    return st;
}

void st_add(SegmentTree *st, int a, data_t x){
    int k = a+st->n-1;
    data_t* segtree = st->segtree;
    data_t (*op)(data_t, data_t) = st->op;
    segtree[k] = op(x, segtree[k]);
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = op(segtree[2*k+1], segtree[2*k+2]);
    }
}

void st_subst(SegmentTree *st, int a, data_t x){
    int k = a+st->n-1;
    data_t* segtree = st->segtree;
    data_t (*op)(data_t, data_t) = st->op;
    segtree[k] = x;
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = op(segtree[2*k+1], segtree[2*k+2]);
    }
}

data_t st_get_one(SegmentTree* st, int a){
    return st->segtree[a+st->n-1];
}

data_t st_get(SegmentTree* st, int l, int r){
    data_t* segtree = st->segtree;
    data_t (*op)(data_t, data_t) = st->op;
    data_t res = st->ide;
    int n = st->n;
    int depth = st->depth;
    int count, a, b, left, right;
    int i = 0;
    for (;i<depth;++i) {
        count = (1<<i)-1;
        a = (r+1)/n;
        if (l<=0) b = -1;
        else b = (l-1)/n;
        if (a-b == 3){
            res = op(segtree[count+b+1],res);
            res = op(segtree[count+b+2],res);
            right = a*n;
            left = (b+1)*n-1;
            break;
        }
        if (a-b == 2){
            res = op(segtree[count+b+1],res);
            right = a*n;
            left = (b+1)*n-1;
            break;
        }
        n /= 2;
    }
    int n1 = n/2;
    for (int j=i+1;j<depth;++j){
        count = (1<<j)-1;
        a = (left+1)/n1;
        if (l<=0) b = -1;
        else b = (l-1)/n1;
        if (a-b == 2){
            res = op(segtree[count+b+1],res);
            left = (b+1)*n1-1;                
        }
        n1 /= 2;
    }

    n1 = n/2;
    for (int j=i+1;j<depth;++j){
        count = (1<<j)-1;
        a = (r+1)/n1;
        if (right<=0) b = -1;
        else b = (right-1)/n1;
        if (a-b == 2){
            res = op(segtree[count+b+1],res);
            right = a*n1;                
        }
        n1 /= 2;
    }
    return res;
}

