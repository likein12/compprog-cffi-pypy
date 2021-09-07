//TAG=lcm

typedef ll st_data_t_TAG;

st_data_t_TAG st_op_TAG(st_data_t_TAG a, st_data_t_TAG b){
    if (a==0) return b;
    if (b==0) return a;
    st_data_t_TAG tmp, _a, _b;
    _a = a;
    _b = b;
    if (a<b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (a%b!=0){
        tmp = a;
        a = b;
        b = tmp%b;
    }
    return _a*(_b/b);
}

st_data_t_TAG st_ide_TAG(){
    return 0;
}