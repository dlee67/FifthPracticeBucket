import heapq

collection = [10, 3, 3, 4, 5, 6]
heapq.heapify(collection) # min heap

print(collection)
# Returns [3, 3, 6, 4, 5, 10]
print(heapq.heappop(collection))
# Returns 3

# Python doesn't have a max heap, I have to something funky with it.
# https://stackoverflow.com/questions/48255849/how-to-get-the-max-heap-in-python

'''
Considering how I need to do something like the below,
I think it's just better to use PriorityQueue if I need a max heap. 
'''
# heap = []
# for num, c in count.items():
#   heap.append((-c, num))