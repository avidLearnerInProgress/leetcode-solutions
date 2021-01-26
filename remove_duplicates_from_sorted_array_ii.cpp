class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
		//if size is less than or equal to 2 then the array is already sorted
        if(n <= 2)  return n;
        
        int i,j;
		//if first 2 elements are in pair the start checking from third element
        if(a[0] == a[1])    i = j = 2;
        else i = j = 1; //else start from 2nd element
        
        while(j<n && i<n){
			//increment j while we do not encounter an element which is greater than the preiously occured pair of elements before ith place, i.e. (i-1)the and (i-2)th element
            while(j < n && a[j] == a[i-1] && a[j] == a[i-2])    j++;  
			//if no such element is present as in case of [1,1,1] then break;
            if(j>=n) break;
			//else swap that ith element and new element at jth position
            swap(a[i],a[j]);
			//continue the process for the next ith place and next jth element
            i++;
            j++;
        }
        
		//return i as i no. of elements are those whose frequency is 1 or 2
        return i;
    }
};
