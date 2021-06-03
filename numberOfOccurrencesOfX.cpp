#include<bits/stdc++.h>
using namespace std;


/*
Can be converted to a single call by passing a bool flag but this is more readable
*/

int binarySearchForStartIndex(vector<int> &a, int x) {
    int start = 0, end = a.size() - 1, mid = 0;
    int result = -1;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(x == a[mid]) {
            result = mid;
            end = mid - 1;
        }
        else if(x < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return result;
}


int binarySearchForEndIndex(vector<int> &a, int x) {
    int start = 0, end = a.size() - 1, mid = 0;
    int result = -1;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(x == a[mid]) {
            result = mid;
            start = mid + 1;
        }
        else if(x < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return result;
}

//find start and end of same number using binarySearch and then subtract the distance
int findOccurrencesOfX(vector<int> &a, int x) {
    int start, end;
    
    start = binarySearchForStartIndex(a, x);
    if(start == -1) //not present 
        return -1;
    
    end = binarySearchForEndIndex(a, x);
    return end - start + 1;
}

int main() {
    vector<int> A = {1, 1, 2, 2, 2, 2, 3};
    cout<<findOccurrencesOfX(A, 2)<<"\n";

    vector<int> B = {1, 1, 2, 2, 2, 2, 3};
    cout<<findOccurrencesOfX(B, 4)<<"\n";

	return 0;
}
