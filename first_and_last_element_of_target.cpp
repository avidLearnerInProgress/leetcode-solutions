class Solution{
public:
    int binarySearch(vector<int>& n, int t, bool flag){
        if(n.size() == 0) return -1;
        
        int l = 0, h = n.size();
        
        while(l < h){
            
            int mid = (l+h)/2;
            if(n[mid] > t || (n[mid] == t && flag))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int l = binarySearch(nums , target, true);
        if(l == nums.size() || nums[l] != target)
            return {-1, -1};
        
        return {l, binarySearch(nums, target, false)-1};
    }
};