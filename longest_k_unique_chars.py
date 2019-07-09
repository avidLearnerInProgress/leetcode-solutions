from collections import deque
for _ in range(int(input())):
    s=input()
    n=int(input())
    q=deque()
    i=0
    l=0
    while i<len(s):
        if len(set(q)) <n:
            q.append(s[i])
            i+=1
        elif len(set(q))==n:
            l=max(l,len(q))
            q.append(s[i])
            i+=1
        elif len(set(q))>n:
            while len(set(q))>n:
                q.popleft()
    if len(set(q))==n:
        l=max(l,len(q))
    if l==0:
        print(-1)
    else:    
        print(l)