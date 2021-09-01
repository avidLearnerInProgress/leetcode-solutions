class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        /*
            The idea is :-
            
            - Ladder allows infinite jumps and bricks have h[i+1] - h[i] possible jumps at given i.
            We have to use ladder juidiciously.
            
            - This means, greddily picking up bricks and ensuring that we run out of bricks first. then if ladders are remaining, use them.
            
            - Also, we have to find the place where we used maximum number of bricks and change it to ladder so that we can regain those many bricks that can be used ahead. => For this purpose we use a maxHeap to maintain the count of bricks used.

        */
        
        if(heights.size() == 0) return 0;
        
        priority_queue<int> bricksUsed; //maxHeap;

        for(int i = 0; i < heights.size() - 1; ++i) {
            
            if(heights[i] >= heights[i+1]) continue; //prev >= next
            
            int difference = heights[i+1] - heights[i];
            bricksUsed.push(difference);
            bricks -= difference;
            
            if(bricks >= 0) continue; //more usage of bricks possible
            
            if(ladders == 0) return i; //if we are out of ladders, that's the furthest we can reach
            
            bricks += bricksUsed.top(); //pick the most used bricks(most difference) and then replace it with ladder; thereby regaining the bricks
            bricksUsed.pop(); 
            ladders--;
        }
        
        return heights.size() - 1;
        
    }
};
