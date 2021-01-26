unsortedList = [7, 2, 3, 1, 0, 9, 10]
x = lambda a : a + 10

print(x(5))
unsortedList.sort()
# print(unsortedList.sort()) this doesn't return anything.
print(unsortedList)

QueueOfHeights = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
QueueOfHeights.sort(key=lambda x:(-x[0], x[1]))
# Gives me [[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]]
QueueOfHeights.sort(key=lambda x:(x[0], x[1])) 
# Gives me [[4, 4], [5, 0], [5, 2], [6, 1], [7, 0], [7, 1]]
print(QueueOfHeights)
# This is so bizzare ...
'''
Notice how QueueOfHeights.sort(key=lambda x:(x[0], x[1])) will give the dictionary back
to me, where the "keys" are in ascending order.

Vice versa, QueueOfHeights.sort(key=lambda x:(-x[0], x[1])) will give me the dictionary back
to me, where the "keys" are in descending order.

https://docs.python.org/3/howto/sorting.html

This is super trippy.
'''