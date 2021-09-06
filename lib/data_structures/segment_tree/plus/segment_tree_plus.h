//plus=plus

typedef int64_t st_data_t_plus;

st_data_t_plus st_op_plus(st_data_t_plus a, st_data_t_plus b){
    return a+b;
}

st_data_t_plus st_ide_plus(){
    return 0;
}typedef struct {
    int n;
    int depth;
    st_data_t_plus *segtree;
} SegmentTree_plus;


SegmentTree_plus* st_init_plus(st_data_t_plus *array, int _length) {
    SegmentTree_plus* st = (SegmentTree_plus*)malloc(sizeof(SegmentTree_plus));
    int n = 1;
    int depth = 1;
    while (n<_length) {
        n*=2;
        depth++;
    }
    (*st).n = n;
    (*st).depth = depth;
    (*st).segtree = (st_data_t_plus*)malloc((2*n-1)*sizeof(st_data_t_plus));
    st_data_t_plus* segtree = (*st).segtree;
    for (int i=n-1;i<2*n-1;++i) {
        if (n-1<=i && i<n-1+_length) segtree[i] = array[i-n+1];
        else segtree[i] = st_ide_plus();
    }
    for (int i=n-2;i>=0;--i) segtree[i] = st_op_plus(segtree[i*2+1],segtree[i*2+2]);
    return st;
}

void st_add_plus(SegmentTree_plus *st, int a, st_data_t_plus x){
    int k = a+st->n-1;
    st_data_t_plus* segtree = st->segtree;
    segtree[k] = st_op_plus(x, segtree[k]);
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = st_op_plus(segtree[2*k+1], segtree[2*k+2]);
    }
}

void st_subst_plus(SegmentTree_plus *st, int a, st_data_t_plus x){
    int k = a+st->n-1;
    st_data_t_plus* segtree = st->segtree;
    segtree[k] = x;
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = st_op_plus(segtree[2*k+1], segtree[2*k+2]);
    }
}

st_data_t_plus st_get_one_plus(SegmentTree_plus* st, int a){
    return st->segtree[a+st->n-1];
}

st_data_t_plus st_get_allrange_plus(SegmentTree_plus* st){
    return st->segtree[0];
}

st_data_t_plus st_get_plus(SegmentTree_plus* st, int l, int r){
    r--;
    st_data_t_plus* segtree = st->segtree;
    st_data_t_plus res = st_ide_plus();
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
            res = st_op_plus(segtree[count+b+1],res);
            res = st_op_plus(segtree[count+b+2],res);
            right = a*n;
            left = (b+1)*n-1;
            break;
        }
        if (a-b == 2){
            res = st_op_plus(segtree[count+b+1],res);
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
            res = st_op_plus(segtree[count+b+1],res);
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
            res = st_op_plus(segtree[count+b+1],res);
            right = a*n1;
        }
        n1 /= 2;
    }
    return res;
}
