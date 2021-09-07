from _compprog_cffi import ffi, lib
from collections import deque
 
scanner_ll = lib.scanner_ll
scanner_ll_multi = lib.scanner_ll_multi
scanner_string = lib.scanner_string
printer_ll_one = lib.printer_ll_one
printer_ll_array_v = lib.printer_ll_array_v
printer_ll_array_h = lib.printer_ll_array_h

hq_init_ll = lib.hq_init_ll
hq_get_size_ll = lib.hq_get_size_ll
hq_pop_ll = lib.hq_pop_ll
hq_top_ll = lib.hq_top_ll
hq_push_ll = lib.hq_push_ll
 
Q = scanner_ll()
 
hq = hq_init_ll()
dq = deque()
 
for i in range(Q):
    q = scanner_ll()
    if q==1:
        dq.append(scanner_ll())
    elif q==2:
        if hq_get_size_ll(hq)>0:
            printer_ll_one(hq_pop_ll(hq))
        else:
            printer_ll_one(dq.popleft())
    else:
        while dq:
            hq_push_ll(hq,dq.popleft())