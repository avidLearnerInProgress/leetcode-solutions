# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        
        
        current, prev = head, ListNode(0)
        count = 0
        
        while current:
            count += 1
            current = current.next
            
        meanSize = count // k # size of each window
        moreThanAverageGroups = count % k  # number of windows that are +1 than the mean size of every window
        
        parts, current = [], head
        
        for _ in range(k): 
            if current:
                
                parts.append(current) # append the current head
                maxSizeOfWindow = meanSize + 1 if moreThanAverageGroups > 0 else meanSize #check how many to occupy in the new window 
                
                moreThanAverageGroups -= 1
                
                for _ in range(maxSizeOfWindow):
                    prev, current = current, current.next
                
                prev.next = None  #end of current list
                
            else:
                parts.append(None)
        return parts
            
            
            
        
            
        
