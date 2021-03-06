from collections import OrderedDict 
  
print("This is a Dict:\n") 
d = {} 
d['a'] = 1
d['b'] = 2
d['c'] = 3
d['d'] = 4
  
for key, value in d.items(): 
    print(key, value)

print("\nThis is an Ordered Dict:\n") 
od = OrderedDict() 
od['a'] = 1
od['b'] = 2
od['c'] = 3
od['d'] = 4
  
for key, value in od.items(): 
    print(key, value) 

# https://www.geeksforgeeks.org/ordereddict-in-python/
# There is literally no difference now, and I am assuming OrderedDict is now 
# the default dictionary for Python.
# https://www.blog.pythonlibrary.org/2018/02/27/python-3-7-dictionaries-now-ordered/
# and it is ...
