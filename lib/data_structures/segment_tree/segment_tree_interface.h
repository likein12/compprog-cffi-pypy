typedef struct {
    int n;
    int depth;
    st_data_t_TAG *segtree;
} SegmentTree_TAG;

SegmentTree_TAG* st_init_TAG(st_data_t_TAG *array, int _length);
void st_add_TAG(SegmentTree_TAG *st, int a, st_data_t_TAG x);
void st_subst_TAG(SegmentTree_TAG *st, int a, st_data_t_TAG x);
st_data_t_TAG st_get_one_TAG(SegmentTree_TAG* st, int a);
st_data_t_TAG st_get_allrange_TAG(SegmentTree_TAG* st);
st_data_t_TAG st_get_TAG(SegmentTree_TAG* st, int l, int r);