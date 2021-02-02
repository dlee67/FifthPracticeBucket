someVal = 5 if True else 0
print(someVal)

someVal = 0 if False else 5
print(someVal)

someVal = "Correct string" if 'True' == 'True' else 'Wrong String'
print(someVal)

someVal = "Wrong String" if 'True' == 'False' else 'Correct string'
print(someVal)