{
#Initial Template for Python 3
if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        n=int(input())
        print(numberOf2sinRange(n))
}
''' This is a function problem.You only need to complete the function given below '''
#User function Template for python3
def number0f2s(n):
    curr = str(n)
    return curr.count('2')
    #add Code here
    
def numberOf2sinRange(n):
    res = 0
    for i in range(1, n+1):
        res += number0f2s(i)
    return res
    #add code here