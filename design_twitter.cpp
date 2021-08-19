class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int> > followersMap; //[userId => {followId, followId, ...}]
    unordered_map<int, vector<pair<int, int>> > tweetMap; //[userId => [(tweetId, timeStamp), (tweetId, timeStamp), ...]]
        
    /** Initialize your data structure here. */
    Twitter(): timeStamp(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // cout<<userId<<" "<<tweetId<<" "<<timeStamp<<"\n";
        tweetMap[userId].emplace_back(tweetId, timeStamp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        
        //heapify all tweets for userId
        for(auto &[idOfTweet, timeOfTweet] : tweetMap[userId]) {
            maxHeap.emplace(timeOfTweet, idOfTweet);
        }
        
        //heapify all followerIds for userId and eventually all tweets for each of the followerIds
        for(auto &followerId : followersMap[userId]) {
            for(auto &[idOfTweet, timeOfTweet] : tweetMap[followerId]) {
                maxHeap.emplace(timeOfTweet, idOfTweet);
            }
        }
        
        vector<int> newsFeed; //okay finally! reached the result part :p
        newsFeed.reserve(10);
        
        while(newsFeed.size() < 10 and !maxHeap.empty()) {
            auto tweetId = maxHeap.top().second;
            // cout<<tweetId<<"\n";
            newsFeed.emplace_back(tweetId);
            maxHeap.pop();
        }
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followersMap[followerId].emplace(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followersMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
