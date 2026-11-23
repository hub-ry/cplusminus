```
for x in nums:

for i,x in enumerate(nums):

for a, b in zip(s,t): #paired characters, stops at the shorter string

for a in nums1:
  for b in nums2:
```


dictionaries:
```
lookup = {}
lookup[key] = value

if key in lookup:
  value = lookup[key]

count = {}
count[key] = count.get(key, 0) + 1  # use 0 if key is missing
```

grouping and hashable keys
- lists can't be dictionary keys
- defaultdict(list) creates an empty list the first time you access a missing key with groups[key]. There's also defaultdict(int) if you wnat missing keys to start at 0
```
from collections import defaultdict

groups = defaultdict(list)
groups[key].append(word)
result = list(groups.values())

sorted_chars = sorted(word)
key = tuple(sorted_cars)
key = "".join(sorted_chars)
```

Sets, runnning totals, and state
```
seen = set(nums)
seen.add(x)

if x in seen:


while x in seen:
  x += 1


total = 0
total += x
best = max(best,length)
```
