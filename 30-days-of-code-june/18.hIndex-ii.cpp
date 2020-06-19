class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int size_c = citations.size();
        int left = 0, right = size_c - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] < size_c - mid) left = mid + 1;
            else right = mid - 1;
        }
        return size_c - left;
    }
};
