#code
from collections import Counter
n = int(input())

for i in range(n):
    _ = int(input())
    tc = list(map(str, input().split(' ')))
    counter = Counter()
    for i in range(len(tc)):
        counter[tc[i]] += 1
    cn = 0
    for k,v in counter.items():
        if v == 2:
            cn += 1
    print(cn)