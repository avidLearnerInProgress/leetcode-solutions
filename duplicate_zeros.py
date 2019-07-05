class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        zero_shifts = arr.count(0)
        l = len(arr)
        for i in range(l-1, -1, -1):
            if i + zero_shifts < l:
                arr[i + zero_shifts] = arr[i]
                #print(i, zero_shifts, arr[i + zero_shifts])
            if arr[i] == 0:
                zero_shifts -= 1
                if i + zero_shifts < l:
                    arr[i + zero_shifts] = 0
                    #print(i, zero_shifts, arr[i + zero_shifts])
        
                
        