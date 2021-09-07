typedef struct {
    int n;
    int depth;
    st_data_t_TAG *segtree;
} SegmentTree_TAG;


SegmentTree_TAG* st_init_TAG(st_data_t_TAG *array, int _length) {
    SegmentTree_TAG* st = (SegmentTree_TAG*)malloc(sizeof(SegmentTree_TAG));
    int n = 1;
    int depth = 1;
    while (n<_length) {
        n*=2;
        depth++;
    }
    (*st).n = n;
    (*st).depth = depth;
    (*st).segtree = (st_data_t_TAG*)malloc((2*n-1)*sizeof(st_data_t_TAG));
    st_data_t_TAG* segtree = (*st).segtree;
    for (int i=n-1;i<2*n-1;++i) {
        if (n-1<=i && i<n-1+_length) segtree[i] = array[i-n+1];
        else segtree[i] = st_ide_TAG();
    }
    for (int i=n-2;i>=0;--i) segtree[i] = st_op_TAG(segtree[i*2+1],segtree[i*2+2]);
    return st;
}

void st_add_TAG(SegmentTree_TAG *st, int a, st_data_t_TAG x){
    int k = a+st->n-1;
    st_data_t_TAG* segtree = st->segtree;
    segtree[k] = st_op_TAG(x, segtree[k]);
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = st_op_TAG(segtree[2*k+1], segtree[2*k+2]);
    }
}

void st_subst_TAG(SegmentTree_TAG *st, int a, st_data_t_TAG x){
    int k = a+st->n-1;
    st_data_t_TAG* segtree = st->segtree;
    segtree[k] = x;
    while (k>0) {
        k = (k-1)/2;
        segtree[k] = st_op_TAG(segtree[2*k+1], segtree[2*k+2]);
    }
}

st_data_t_TAG st_get_one_TAG(SegmentTree_TAG* st, int a){
    return st->segtree[a+st->n-1];
}

st_data_t_TAG st_get_allrange_TAG(SegmentTree_TAG* st){
    return st->segtree[0];
}

st_data_t_TAG st_get_TAG(SegmentTree_TAG* st, int l, int r){
    r--;
    st_data_t_TAG* segtree = st->segtree;
    st_data_t_TAG res = st_ide_TAG();
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
            res = st_op_TAG(segtree[count+b+1],res);
            res = st_op_TAG(segtree[count+b+2],res);
            right = a*n;
            left = (b+1)*n-1;
            break;
        }
        if (a-b == 2){
            res = st_op_TAG(segtree[count+b+1],res);
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
            res = st_op_TAG(segtree[count+b+1],res);
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
            res = st_op_TAG(segtree[count+b+1],res);
            right = a*n1;                
        }
        n1 /= 2;
    }
    return res;
}

