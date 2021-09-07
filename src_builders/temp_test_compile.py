from cffi import FFI
import os

ffibuilder = FFI()

# cdef() expects a single string declaring the C types, functions and
# globals needed to use the shared object. It must be in valid C syntax.
ffibuilder.cdef("""
typedef long long ll;
typedef double lf;

//EMBEDPOINT
""")

# set_source() gives the name of the python extension module to
# produce, and some C source code as a string.  This C code needs
# to make the declarated functions, types and globals available,
# so it is often just the "#include".
ffibuilder.set_source("_compprog_cffi",
"""
     #include "test_compprog.h"   // the C header of the library     #include "../lib/data_structures/cheapq/ll/instance.h"   // the C header of the library     #include "../lib/data_structures/cheapq/ll/instance.h"   // the C header of the library
""")

if __name__ == "__main__":
    os.chdir("lib/")
    ffibuilder.compile(verbose=True)