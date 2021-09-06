typedef struct {
    int length;
    int* table;
    int* n_members;
} Dsu;

Dsu *DsuInit(int length){
    Dsu *dsu = (Dsu*)malloc(sizeof(Dsu));
    (*dsu).length = length;
    (*dsu).table = (int*)malloc(length*sizeof(int));
    (*dsu).n_members = (int*)malloc(length*sizeof(int));
    for (int i=0;i<length;++i){
        (*dsu).table[i] = -1;
        (*dsu).n_members[i] = 1;
    }
    return dsu;
}

int dsu_find(Dsu *dsu, int x){
    int y = dsu->table[x];
    if (y < 0) return x;
    int z = dsu_find(dsu, y);
    dsu->table[x] = z;
    return z;
}

void dsu_union(Dsu *dsu, int x, int y){
    int s1 = dsu_find(dsu, x);
    int s2 = dsu_find(dsu, y);
    int m1 = dsu->n_members[s1];
    int m2 = dsu->n_members[s2];
    if (s1==s2) return;
    if (m1<=m2){
        dsu->table[s1] = s2;
        dsu->n_members[s2] = m1+m2;
    } else {
        dsu->table[s2] = s1;
        dsu->n_members[s1] = m1+m2;
    }
}
