#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
private:
    long timeStamp;
    std::unordered_map<int, std::vector<std::pair<long, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<long, int>> maxHeap;

        for (auto& tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        for (int followeeId : following[userId]) {
            for (auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        std::vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

int main() {
    Twitter tw;
    tw.postTweet(1, 5);
    auto feed = tw.getNewsFeed(1);
    std::cout << "Primer tweet del feed de usuario 1: " << feed[0] << std::endl;
    return 0;
}
