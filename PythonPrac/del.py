x = "hello"

# Literally makes a dangling pointer.
del x

# The below will create an error.
print(x)