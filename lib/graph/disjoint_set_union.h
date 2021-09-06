typedef struct {
    int length;
    int* dsu;
} Dsu;

Dsu* dsu_init(int length){
    Dsu *dsu = (Dsu*)malloc(sizeof(Dsu));
    (*dsu).length = length;
    (*dsu).dsu = (int*)malloc(length*sizeof(int));
    for (int i=0;i<length;++i){
        (*dsu).dsu[i] = -1;
    }
    return dsu;
}

int dsu_find(Dsu *dsu, int x){
    int y = dsu->dsu[x];
    if (y < 0) return x;
    int z = dsu_find(dsu, y);
    dsu->dsu[x] = z;
    return z;
}

void dsu_union(Dsu *dsu, int x, int y){
    int s1 = dsu_find(dsu, x);
    int s2 = dsu_find(dsu, y);
    int m1 = -dsu->dsu[s1];
    int m2 = -dsu->dsu[s2];
    if (s1==s2) return;
    if (m1<=m2){
        dsu->dsu[s1] = s2;
        dsu->dsu[s2] = -(m1+m2);
    } else {
        dsu->dsu[s2] = s1;
        dsu->dsu[s1] = -(m1+m2);
    }
}

int dsu_n_members(Dsu *dsu, int x){
    int s = dsu_find(dsu, x);
    return -dsu->dsu[s];
}