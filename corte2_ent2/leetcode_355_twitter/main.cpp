#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>> maxHeap;

        for (const auto& t : tweets[userId]) {
            maxHeap.push(t);
        }

        for (int followeeId : following[userId]) {
            for (const auto& t : tweets[followeeId]) {
                maxHeap.push(t);
            }
        }

        std::vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
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

void printFeed(const std::vector<int>& feed) {
    std::cout << "[";
    for (size_t i = 0; i < feed.size(); ++i) {
        std::cout << feed[i];
        if (i + 1 < feed.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "=== LeetCode 355: Design Twitter ===\n" << std::endl;

    Twitter twitter;

    std::cout << "postTweet(1, 5) -> usuario 1 publica tweet 5" << std::endl;
    twitter.postTweet(1, 5);

    std::cout << "getNewsFeed(1): ";
    printFeed(twitter.getNewsFeed(1));

    std::cout << "\nfollow(1, 2) -> usuario 1 sigue a usuario 2" << std::endl;
    twitter.follow(1, 2);

    std::cout << "postTweet(2, 6) -> usuario 2 publica tweet 6" << std::endl;
    twitter.postTweet(2, 6);

    std::cout << "getNewsFeed(1): ";
    printFeed(twitter.getNewsFeed(1));

    std::cout << "\nunfollow(1, 2) -> usuario 1 deja de seguir a usuario 2" << std::endl;
    twitter.unfollow(1, 2);

    std::cout << "getNewsFeed(1): ";
    printFeed(twitter.getNewsFeed(1));

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
