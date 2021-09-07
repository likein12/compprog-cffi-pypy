//TAG=affinem

typedef struct {
    ll a;
    ll b;
} st_data_t_TAG;

st_data_t_TAG st_op_TAG(st_data_t_TAG a, st_data_t_TAG b){
    return {a.a*b.a%MOD, (a.b*b.a+b.b)%MOD};
}

st_data_t_TAG st_ide_TAG(){
    return {1,0};
}