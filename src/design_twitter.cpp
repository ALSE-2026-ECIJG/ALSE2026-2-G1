class Twitter {
private:
    long long timeStamp;
    std::unordered_map<int, std::list<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        following[userId].insert(userId);
        for (int followeeId : following[userId]) {
            if (tweets.count(followeeId)) {
                for (auto& tweet : tweets[followeeId]) {
                    minHeap.push(tweet);
                    if (minHeap.size() > 10) {
                        minHeap.pop();
                    }
                }
            }
        }
        
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.insert(result.begin(), minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

