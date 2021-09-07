//TAG=minf

typedef lf st_data_t_TAG;

st_data_t_TAG st_op_TAG(st_data_t_TAG a, st_data_t_TAG b){
    if (a<b) return a;
    else return b;
}

st_data_t_TAG st_ide_TAG(){
    return DBL_MAX;
}
