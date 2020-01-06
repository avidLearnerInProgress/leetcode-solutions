/*This is a function problem.You only need to complete the function given below*/

int helper(int arr[], int strt, int end){
    while(strt <= end){
        int mid = strt + (end - strt)/2;
        if(arr[mid] == 1 && arr[mid - 1] == 0)
            return mid;
        else if(arr[mid] == 1)
            end = mid - 1;
        else 
            strt = mid + 1;
    }
    return -1;
}

int transitionPoint(int arr[],int n)
{
// Your code goes here
    int strt = 0, end = n -1;
    return helper(arr, strt, end);
}