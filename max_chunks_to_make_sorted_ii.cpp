class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        /*     
            //if we have all elements towards left less than all elements towards right, then we have discovered a chunk
            //keep track of right min using rightMinArray
            //iterate over the actual array and calculate left max 
        */
        
        int N = arr.size();
        vector<int> trackRightMin(N);
        int result = 0, max_ = INT_MIN;
        
        
        trackRightMin[N-1] = arr[N-1];
        for(int i=N-2; i>=0; --i) 
            trackRightMin[i] = min(trackRightMin[i+1], arr[i]);
        
        for(int i=0; i<N-1; ++i) {
            max_ = max(max_, arr[i]);
            if(max_ <= trackRightMin[i+1]) ++result;
        }
        return result+1;
    }
};
