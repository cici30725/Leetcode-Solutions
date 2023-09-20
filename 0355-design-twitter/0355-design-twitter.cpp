class Twitter {
public:
    using TweetNode = list<pair<int, int>>::iterator; // <tweetId, userId>
    int curTime = 0;
    unordered_map<int, list<pair<int, int>>> userTweets; // <userId, [TweetNode...]>
    unordered_map<int, unordered_set<int>> followees; // <followerId, [followeeId...]>
    unordered_map<int, int> tweet_to_time; // <tweetId, time>
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        //cout<<"post"<<endl;
        userTweets[userId].push_front({tweetId, userId});
        tweet_to_time[tweetId] = curTime;
        curTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // cout<<"getNews"<<endl;
        map<int, TweetNode> M; // <time, TweetNode>
        for(int id : followees[userId]){
            // list<int>::iterator tweetIt = userTweets[id].begin();
            if(userTweets.find(id)==userTweets.end())
                continue;
            TweetNode tweet = userTweets[id].begin();
            int tweetTime = tweet_to_time[tweet->first];
            M[tweetTime] = tweet;
        }
        
        if(userTweets.find(userId)!=userTweets.end()){
            TweetNode tweet = userTweets[userId].begin();
            int tweetTime = tweet_to_time[tweet->first];
            M[tweetTime] = tweet;
        }
        
        vector<int> tweetResults;
        for(int i=0; i<10 && !M.empty(); i++){
            auto& [time, tweet] = *M.rbegin();
            tweetResults.push_back(tweet->first);
            int cur_user_idx = tweet->second;
            tweet++;
            // cout<<tweet->first<<" "<<tweet->second<<endl;
            if(tweet!=userTweets[cur_user_idx].end()){
                int next_time = tweet_to_time[tweet->first];
                M[next_time] = tweet;
            }
            M.erase(time);
        }
        
        return tweetResults;
    }
    
    void follow(int followerId, int followeeId) {
        // cout<<"follow"<<endl;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // cout<<"unfollow"<<endl;
        followees[followerId].erase(followeeId);
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