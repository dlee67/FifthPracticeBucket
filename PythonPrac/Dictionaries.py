states = {
    'Oregon': 'OR',
    'Florida': 'FL',
    'California': 'CA',
    'New York': 'NY',
    'Michigan': 'MI'
}

print("Michigan's abbreviation is: ", states['Michigan'])
print("Florida's abbreviation is: ", states['Florida'])

states['Colorado'] = 'CO'

print("Colorado's abbreviation is: ", states['Colorado'])

graph = {}
graph[0] = [1]
graph[0].append(2)
# Prints {0: [1, 2]}
print(graph)

# https://docs.python.org/3/tutorial/datastructures.html
newSet = set()