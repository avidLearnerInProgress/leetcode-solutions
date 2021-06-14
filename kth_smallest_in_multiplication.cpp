/*
Why heap is inefficient here and how we come with a design function -

For Kth-Smallest problems like this, what comes to our mind first is Heap. Usually we can maintain a Min-Heap and just pop the top of the Heap for k times. However, that doesn't work out in this problem. We don't have every single number in the entire Multiplication Table, instead, we only have the height and the length of the table. If we are to apply Heap method, we need to explicitly calculate these m * n values and save them to a heap. The time complexity and space complexity of this process are both O(mn), which is quite inefficient. This is when binary search comes in. Remember we say that designing condition function is the most difficult part? In order to find the k-th smallest value in the table, we can design an enough function, given an input num, determine whether there're at least k values less than or equal to num. The minimal num satisfying enough function is the answer we're looking for. Recall that the key to binary search is discovering monotonicity. In this problem, if num satisfies enough, then of course any value larger than num can satisfy.

*/

class Solution {
    //based on binary search template to solve all BS problems
    bool isEnough(int m, int n, int k, int num) {
        int count = 0;
        
        for(int i = 1; i < m + 1; i++) {
            int add =min (num/i, n);
            if (add == 0)
                break;
            count += add;
        }
        
        return count >= k;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        
        int left = 1, right = m * n;
        
        while(left < right) {
            
            //find mid
            int mid = left + (right-left)/2;
            
            //condition
            if (isEnough(m, n, k, mid))
                right = mid;
            
            //else
            else
                left = mid + 1;
        }
        
        return left;
    }
};
