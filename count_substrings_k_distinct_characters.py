def substr(mystr, k):
    if mystr == None or k == 0:
        return 0
    ls = list()
    for i in range(len(mystr) - (k-1)):
        ls.append(mystr[i:i+k]) # set to remove duplicate k length strings
    
    res = set()
    for ele in ls:
        if len(set(ele)) == k:
            res.add(ele)
    return len(res)

n = int(input())
for i in range(n):
    mystr = str(input())
    k = int(input())
    print(substr(mystr, k))
    