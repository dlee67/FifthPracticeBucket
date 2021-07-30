col = [True] * 4
row = [True] * 4
asc_diag = [True] * (4 * 2 - 1)
desc_diag = [True] * (4 * 2 - 1)

res = []
ones = [1] * 5; 

print(asc_diag)
print(desc_diag)

res.append([i + i for i in ones])
print(res)

# Range returns ... well ... range
print(range(0, 4))
print(len(range(0, 4)))
x = range(0, 4)
print(x[1])