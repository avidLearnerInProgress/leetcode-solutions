#User function Template for python3

'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import defaultdict

# recursive    
#Complete the function below
def diagonal(root):
    #:param root: root of the given tree.
    #return: print out the diagonal traversal,  no need to print new line
    #code here
    if not root:
        return []
    
    def diagonalHelper(root, level):
        d[level].append(root.data)
        
        if root.left: 
            diagonalHelper(root.left, level + 1)
            
        if root.right:
            diagonalHelper(root.right, level)

    d = defaultdict(list)
    diagonalHelper(root, 0)
    result = []
    for k,v in d.items():
        for ele in v:
            result.append(ele)

    return result


# iterative    
#Complete the function below
def diagonal(root):
    #:param root: root of the given tree.
    #return: print out the diagonal traversal,  no need to print new line
    #code here
    if not root:
        return []
    node = root
    result, queue = [], []
    
    while node:
        result.append(node.data)
        
        if node.left:
            queue.append(node.left)
        
        if node.right:
            node = node.right
        
        else:
            if len(queue) > 0:
                node = queue.pop(0)
            else:
                node = None
    
    return result

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(50000)
#Contributed by Sudarshan Sharma
from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
    
if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        diagonalNode = diagonal(root)
        for node in diagonalNode:
            print(node,end=' ')
        print()

# } Driver Code Ends
