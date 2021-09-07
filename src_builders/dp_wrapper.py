code = """
    a
"""

def transpiler(py_code):
    print(py_code)
    print(py_code.split("\n"))
    print(py_code.split("\n")[1].split("    "))

print(transpiler(code))