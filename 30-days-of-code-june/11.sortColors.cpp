class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int start = 0, mid = 0, end = nums.size() - 1;
        
        int pivot = 1;
        while (mid <= end)
        {
            if (nums[mid] < pivot)		 // current element is 0
                swap(nums[start++], nums[mid++]);
            else if (nums[mid] > pivot)	// current element is 2
                swap(nums[mid], nums[end--]);
            else mid++;
        }
    }
        
};
