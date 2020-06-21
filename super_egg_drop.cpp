class Solution {
public:
    int superEggDrop(int K, int N) {
        // K -> totalEggs, N -> totalFloors
        
        vector<vector<int>> dp(K+1, vector<int>(N+1));
        //basecase 1: if totalfloors is 0 or 1, then min trials == totalfloors        
        for(int i=1; i<=K; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        //basecase 2: if totaleggs = 1, then check_eggdrop from floor 0 => n-1
        for(int j=1; j<=N; j++){
            dp[1][j] = j;
        }
        
        int r;
        
        /*
        for each egg..
            check for all the floors..  
        */
        
        /*
        The brute force solution gets TLE. To optimize, we should check for the unnecessary iteration in the for-loops. More specifically, to get the k that best fits each drop, we don't need to go over all floors from 1 to j. As for a fixed k, dp[i][k] goes up as k increases. This means dp[i-1][k-1] will increase and dp[i][j-k] will decrease as k goes from 1 to j. The optimal value of k will be the middle point where the two meet. So to get the optimal k value for dp[i][j], we can do a binary search for k from 1 to j. This will save the third for-loop of k from O(n) to O(logn). Total complexity is O(knlogn).
        */
        
        for(int i=2; i<=K; i++){//for eggs
            int x = 1;
            for(int j=2; j<=N; j++){ //for floors
                
                /*
                dp[i][j] = INT_MAX;
                for(int x=1; x<=j; x++){ //for all permutations of floord
                    
                    //if egg drop..first element inside max..
                    //if egg doesnt drop..second element inside max..
                    r = max(dp[i-1][x-1], dp[i][j-x]) + 1; // + 1 for current trial
                    if(r < dp[i][j])
                        dp[i][j] = r;
                    */
                
                    while(x < j+1 && dp[i-1][x-1] < dp[i][j-x]) x++;
                    dp[i][j] = 1 + dp[i-1][x-1];
                }
        }
        return dp[K][N];
    }
    
};