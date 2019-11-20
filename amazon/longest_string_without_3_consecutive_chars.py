def ls3(A, B, C):
    pq = []
    res = ""
    for k, v in ('a', A), ('b', B), ('c', C):
        heapq.heappush(pq, (-v, k))
    preV, preK = 0, ''
    while pq:
        v, k = heapq.heappop(pq)
        if preV:
            heapq.heappush(pq, (preV, preK))
            preV, preK = 0, ''
        if res[-2:] == k * 2:
            preV, preK = v, k
        else:
            res += k
            if v != -1:
                heapq.heappush(pq, (v + 1, k))
    return res
A, B, C = 1, 1, 6
print(ls3(A, B, C))
A, B, C = 1, 2, 3
print(ls3(A, B, C))