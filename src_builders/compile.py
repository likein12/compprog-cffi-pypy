from cffi import FFI
import os

ffibuilder = FFI()

# cdef() expects a single string declaring the C types, functions and
# globals needed to use the shared object. It must be in valid C syntax.
ffibuilder.cdef("""
    typedef int Boolean;
    typedef int64_t ft_data_t;
    typedef struct {
        size_t length;
        size_t N0;
        ft_data_t* bit;
        ft_data_t (*op)(ft_data_t, ft_data_t);
        ft_data_t ide;
    } FenwickTree;
    void ft_add(FenwickTree* ft, size_t a, ft_data_t w);
    ft_data_t ft_sum(FenwickTree* ft, size_t a);
    FenwickTree* ft_init(ft_data_t* array, size_t length, 
                        ft_data_t (*op)(ft_data_t, ft_data_t), ft_data_t ide,
                        Boolean construct);

    typedef struct {
        int length;
        int* table;
        int* n_members;
    } Dsu;

    Dsu *DsuInit(int length);
    int dsu_find(Dsu *dsu, int x);
    void dsu_union(Dsu *dsu, int x, int y);

    typedef struct {
        int length;
        int depth;
        int n;
        int64_t* q;
    } PriorityQueue;

    PriorityQueue *PriorityQueueInit(int _length);
    int pq_get_size(PriorityQueue *pq);
    int64_t pq_pop(PriorityQueue *pq);
    int64_t pq_top(PriorityQueue *pq);
    void pq_push(PriorityQueue *pq, int64_t x);

    typedef int64_t data_t;

    typedef struct {
        int n;
        int depth;
        data_t *segtree;
        data_t (*op)(data_t, data_t);
        data_t ide;
    } SegmentTree;

    SegmentTree* SegmentTreeInit(data_t *array, int _length, data_t (*op)(data_t, data_t), data_t ide);
    void st_add(SegmentTree *st, int a, data_t x);
    void st_subst(SegmentTree *st, int a, data_t x);
    data_t st_get_one(SegmentTree* st, int a);
    data_t st_get(SegmentTree* st, int l, int r);

    typedef struct set_node{
        int key;
        int rank;
        int size;
        struct set_node *left, *right;
    } set_node;

    set_node* insert(set_node *x, int t);
    set_node* lt(set_node*x,int k);
    set_node* gt(set_node*x,int k);
    set_node* SetInit();

    static int Scanner(void);
    static int* ScannerMulti(int n);
    static char* ScannerString(int n);
    static void Printer(int64_t x);
    static void PrinterOne(int64_t x);
    static void PrinterArray(int64_t *x, int n);
    data_t (*get_operator(const char *str)) (data_t, data_t);
""")

# set_source() gives the name of the python extension module to
# produce, and some C source code as a string.  This C code needs
# to make the declarated functions, types and globals available,
# so it is often just the "#include".
ffibuilder.set_source("_compprog_cffi",
"""
     #include "compprog.h"   // the C header of the library
""")

if __name__ == "__main__":
    os.chdir("lib/")
    ffibuilder.compile(verbose=True)