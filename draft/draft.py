from _compprog_cffi import ffi, lib
 
coset_init = lib.coset_init_ll
insert =  lib.cs_insert_ll
upper_bound = lib.cs_upper_bound_ll
rupper_bound = lib.cs_rupper_bound_ll
 
scan = lib.scanner_ll
prin = lib.printer_ll_one
L,Q = scan(), scan()
 
cs = coset_init()
 
insert(cs, 0)
insert(cs, L)
for i in range(Q):
    if scan()==1:
        x = scan()
        insert(cs, x)
    else:
        x = scan()
        prin(upper_bound(cs, x).key - rupper_bound(cs, x).key)