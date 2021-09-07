from cffi import FFI
import os

ffibuilder = FFI()

# cdef() expects a single string declaring the C types, functions and
# globals needed to use the shared object. It must be in valid C syntax.
ffibuilder.cdef("""
typedef int Boolean;
typedef long long ll;
typedef double lf;

typedef ll hq_data_t_ll;
typedef struct {
    int cap;
    int n;
    hq_data_t_ll* q;
} cheapq_ll;

cheapq_ll *hq_init_ll();
int hq_get_size_ll(cheapq_ll *hq);
hq_data_t_ll hq_pop_ll(cheapq_ll *hq);
hq_data_t_ll hq_top_ll(cheapq_ll *hq);
void hq_push_ll(cheapq_ll *hq, hq_data_t_ll x);

typedef lf hq_data_t_lf;
typedef struct {
    int cap;
    int n;
    hq_data_t_lf* q;
} cheapq_lf;

cheapq_lf *hq_init_lf();
int hq_get_size_lf(cheapq_lf *hq);
hq_data_t_lf hq_pop_lf(cheapq_lf *hq);
hq_data_t_lf hq_top_lf(cheapq_lf *hq);
void hq_push_lf(cheapq_lf *hq, hq_data_t_lf x);

//EMBEDPOINT

static ll scanner_ll();
static ll* scanner_ll_multi(int n);
static char* scanner_string(int n);
static void printer_ll_one(ll x);
static void printer_ll_array_v(ll* x, int n);
static void printer_ll_array_h(ll* x, int n);

""")

# set_source() gives the name of the python extension module to
# produce, and some C source code as a string.  This C code needs
# to make the declarated functions, types and globals available,
# so it is often just the "#include".
ffibuilder.set_source("_compprog_cffi",
"""
     #include "temp_compprog.h"   // the C header of the library
""")

if __name__ == "__main__":
    os.chdir("lib/")
    ffibuilder.compile(verbose=True)