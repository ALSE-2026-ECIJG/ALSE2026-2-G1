#ifndef TWITTER_H
#define TWITTER_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
private:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> userTweets;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> maxHeap;


        unordered_set<int> users = following[userId];
        users.insert(userId);

        for (int u : users) {
            if (userTweets.find(u) != userTweets.end() && !userTweets[u].empty()) {
                int lastIdx = userTweets[u].size() - 1;
                auto& tweet = userTweets[u][lastIdx];

                maxHeap.push({tweet.first, tweet.second, u, lastIdx});
            }
        }

        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int tweetId = top[1];
            int u = top[2];
            int idx = top[3];

            result.push_back(tweetId);


            if (idx > 0) {
                auto& nextTweet = userTweets[u][idx - 1];
                maxHeap.push({nextTweet.first, nextTweet.second, u, idx - 1});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};

#endif
