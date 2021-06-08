class Node(object):
  def __init__(self, val, next=None):
    self.val = val
    self.next = next

  def __str__(self):
    c = self
    answer = ''
    while c:
      answer += str(c.val) if c.val else ""
      c = c.next
    return answer

def merge2(lists):
    head = current = Node(-1)

    # https://www.programiz.com/python-programming/methods/built-in/any
    # The any() function returns True if any element of an iterable is True. If not, any() returns False.
    while any(list is not None for list in lists):
        current_min, i = min((list.val, i)
                             for i, list in enumerate(lists) if list is not None)
        lists[i] = lists[i].next
        current.next = Node(current_min)
        current = current.next
    return head.next

a = Node(1, Node(2, Node(3)))
b = Node(4, Node(5, Node(6)))

print(merge2([a, b]))