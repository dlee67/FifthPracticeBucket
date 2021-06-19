from collections import defaultdict

# x = "hello"

# Literally makes a dangling pointer.
# del x

# The below will create an error.
# print(x)
char_map = defaultdict(int)

char_map['a'] += 1
char_map['b'] += 2
char_map['c'] += 3

print(char_map['b'])

del char_map['b']

# Grabs zero.
print(char_map['b'])