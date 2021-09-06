typedef int64_t ft_data_t;

typedef struct {
    int length;
    int N0;
    ft_data_t* bit;
    ft_data_t (*op)(ft_data_t, ft_data_t);
    ft_data_t ide;
} FenwickTree;


void ft_add(FenwickTree *ft, int a, ft_data_t w){
    ft_data_t* bit = ft->bit;
    ft_data_t (*op)(ft_data_t, ft_data_t) = ft->op;
    int x = a+1;
    while (x <= ft->length){
        bit[x-1] = op(w,bit[x-1]);
        x += x&(-x);
    }
}

ft_data_t ft_sum(FenwickTree *ft, int a){
    int x = a+1;
    ft_data_t* bit = ft->bit;
    ft_data_t (*op)(ft_data_t, ft_data_t) = ft->op;
    ft_data_t res = ft->ide;
    while (x > 0) {
        res = op(bit[x-1], res);
        x -= x&(-x);
    }
    return res;
} 

FenwickTree *ft_init(ft_data_t *array, int length,
                    ft_data_t (*op)(ft_data_t, ft_data_t), ft_data_t ide,
                    Boolean construct){
    FenwickTree *ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    (*ft).length = length;
    (*ft).bit = (ft_data_t*)malloc(length*sizeof(ft_data_t));
    (*ft).op = op;
    (*ft).ide = ide;
    for (int i=0;i<length;++i) (*ft).bit[i] = ide;
    if (construct) for (int i=0;i<length;++i) ft_add(ft,i,array[i]);
    int N0 = 1;
    while (N0*2 <= length) N0 *= 2;
    (*ft).N0 = N0;
    return ft;
}