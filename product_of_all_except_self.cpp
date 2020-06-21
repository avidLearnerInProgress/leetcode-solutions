class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        vector<int> L(nums.size()), R(nums.size());
        
        L[0]=1;
        R[nums.size()-1]=1;

        for(int i=1; i<nums.size();i++){
            L[i] = L[i-1] * nums[i-1];
        }
        
        for(int i=nums.size()-2; i>=0;i--){
            R[i] = R[i+1] * nums[i+1];
        }
        
        vector<int> pb;
        for(int i=0; i<nums.size(); i++){
            pb.push_back(L[i] * R[i]);
        }
        return pb;
    }
};