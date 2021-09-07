typedef ll ft_data_t_TAG;

typedef struct {
    int length;
    int N0;
    ft_data_t_TAG* bit;
} fenwicktree;

void ft_add_TAG(fenwicktree* ft, int a, ft_data_t_TAG w){
    ft_data_t_TAG* bit = ft->bit;
    int x = a+1;
    while (x <= ft->length){
        bit[x-1] = ft_op_TAG(w, bit[x-1]);
        x += x&(-x);
    }
}

ft_data_t_TAG _ft_sum_TAG(fenwicktree* ft, int a){
    int x = a+1;
    ft_data_t_TAG* bit = ft->bit;
    ft_data_t_TAG res = ft_ide_TAG();
    while (x > 0) {
        res = ft_op_TAG(bit[x-1], res);
        x -= x&(-x);
    }
    return res;
} 

fenwicktree* ft_init(ft_data_t_TAG *array, int length, Boolean construct){
    fenwicktree* ft = (fenwicktree*)malloc(sizeof(fenwicktree));
    ft->length = length;
    ft->bit = (ft_data_t_TAG*)malloc(length*sizeof(ft_data_t_TAG));
    for (int i=0;i<length;++i) (*ft).bit[i] = ft_ide_TAG();
    if (construct) for (int i=0;i<length;++i) ft_add_TAG(ft,i,array[i]);
    return ft;
}
