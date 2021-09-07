from _compprog_cffi import ffi,lib

hq_init_lf = lib.hq_init_lf
hq_get_size_lf = lib.hq_get_size_lf
hq_pop_lf = lib.hq_pop_lf
hq_top_lf = lib.hq_top_lf
hq_push_lf = lib.hq_push_lf

hq = hq_init_lf(2)
for i in range(100000):
    hq_push_lf(hq, 10000-i)
print(hq.cap)
for i in range(100000):
    hq_pop_lf(hq)
print(hq.cap)