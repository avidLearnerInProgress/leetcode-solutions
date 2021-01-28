int minSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int sum = 0, low = 0;
    for (int a : arr) {
        sum += (low = max(low + 1, a));
    }
    return sum;
}
