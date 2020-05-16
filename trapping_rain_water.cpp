class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        
        vector<int> maxLeft, maxRight;

        //fill maxLeft
        int maxL = height[0];
        for(auto h : height){
            if(h > maxL)
                maxLeft.push_back(h);
            else
                maxLeft.push_back(maxL);
        }

        //fill maxRight
        int maxR = height[height.size()-1];
        for(auto h : height){
            if(h > maxL)
                maxRight.push_back(h);
            else
                maxRight.push_back(maxR);
        }

        //display maxLeft and maxRight
        //for(auto element : maxLeft) cout<<element<<"\t";
        //cout<<"\n";
        //for(auto element : maxRight) cout<<element<<"\t";

        vector<int> minOfLR;
        for(auto i=0; i<maxLeft.size(); i++)
            minOfLR.push_back(min(maxLeft[i], maxRight[i]));

        vector<int> water;
        for(auto i=0; i<height.size(); i++)
            water.push_back(minOfLR[i] - height[i]);

        auto total_trapped_water = 0;
        //cout<<"\n";
        for(auto w : water) total_trapped_water += w;
        //cout<<total_trapped_water;

            return total_trapped_water;
    }
};