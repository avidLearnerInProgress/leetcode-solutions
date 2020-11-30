class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto num : nums) {
            ones = ones ^ num & ~twos; // if num not in twos, add it to ones
            twos = twos ^ num & ~ones; // if num not in ones, add it to twos
        }
        return ones;
    }
};


/*
Previous attempt -

class Solution {
public:
    int singleNumber(vector<int>& nums) {
         
        int n=nums.size();
        long ans;
        int x, t;
        ans=0;
        int p=0;
		// We have 32 bits integers as input
        for(int i=0;i<32;i++)
        {
            t=0;
            //calculate sum of ith bit for all numbers in nums
            for(int j=0;j<n;j++)
            {
                x=nums[j]&1;
                t=t+x;
                nums[j]=nums[j]>>1;
            }
            t=t%3;
            //the bit that does not occur as multiple of 3 is left as a remainder 
            ans=ans+t*pow(2,p);
            p++;
        }
        return ans;
    }
};


*/
