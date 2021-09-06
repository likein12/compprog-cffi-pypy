import base64
import sys
import pyperclip

print("building the source file for submission...")

if sys.argv[1]=="NOT_COMPILE":
    binary_path = "./bin/_compprog_cffi.pypy36-pp73-x86_64-linux-gnu.so"
elif sys.argv[1]=="COMPILE":
    binary_path = "./built_files/_compprog_cffi.pypy36-pp73-x86_64-linux-gnu.so"
else:
    print("argument error :")

a = open(binary_path, "rb").read()
binary = base64.b85encode(a)

header = """import base64

binary = BINARY_CODE
open('./_compprog_cffi.pypy36-pp73-x86_64-linux-gnu.so','wb').write(base64.b85decode(binary))
"""

code = "\n".join([line.rstrip() for line in open("./draft/draft.py", "r")])
src = header.replace("BINARY_CODE", str(binary)) + code

open("./built_files/main.py", "w").write(src)

pyperclip.copy(src)

print("you can submit ./built_files/main.py")
print("The source code has already been written in your clipboard! Paste!")