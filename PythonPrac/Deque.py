from collections import deque

q = deque([5, 6, 7])

print(q.popleft())
print(q.pop()) #pops right
q.append(8)
print(q.popleft())
print(q.pop())