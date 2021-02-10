import heapq

collection = [10, 3, 3, 4, 5, 6]
heapq.heapify(collection) # min heap

print(collection)
# Returns [3, 3, 6, 4, 5, 10]
print(heapq.heappop(collection))

# Python doesn't have a max=heap, I have to use this thing called PriorityQueue.
# https://stackoverflow.com/questions/48255849/how-to-get-the-max-heap-in-python