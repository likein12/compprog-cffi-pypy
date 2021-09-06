data_t op_plus(data_t a, data_t b){
    return a+b;
}

data_t op_min(data_t a, data_t b){
    if (a<b) return a;
    else return b;
}

data_t op_max(data_t a, data_t b){
    if (a>b) return a;
    else return b;
}

data_t op_gcd(data_t a, data_t b){
    if (a==-1) return b;
    if (b==-1) return a;
    data_t tmp;
    if (b>a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a%b==0) return b;
    return op_gcd(b,a%b);
}

data_t (*get_operator(const char *str)) (data_t, data_t) {
    if (strcmp(str, "plus") == 0) return op_plus;
    if (strcmp(str, "min") == 0) return op_min;
    if (strcmp(str, "max") == 0) return op_max;
    if (strcmp(str, "gcd") == 0) return op_gcd;
}