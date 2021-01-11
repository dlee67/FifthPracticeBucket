the_count = [1,2,3,4]
laughs = ['lol', 'lel', 'lul', 'lulz']
i = 0

for number in the_count:
    print(f"This is count {number}")

# Python doesn't have this pattern:
# for(int i = 0; i < 10; i++)
# It more or less behaves like Kotlin (well, it's actually other way around because Python is older than Kotlin)

for index in range(0, 10):
    print(f"This is count {index}")

for lol in laughs:
    print(f"{lol}")