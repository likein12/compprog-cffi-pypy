//TAG=affinef

typedef struct {
    lf a;
    lf b;
} st_data_t_TAG;

st_data_t_TAG st_op_TAG(st_data_t_TAG a, st_data_t_TAG b){
    return {a.a*b.a, a.b*b.a+b.b};
}

st_data_t_TAG st_ide_TAG(){
    return {1,0};
}