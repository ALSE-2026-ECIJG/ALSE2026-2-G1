#include <iostream>
#include "Twitter.h"

void printFeed(const std::string& label, const std::vector<int>& feed) {
    std::cout << label << ": [";
    for (std::size_t i = 0; i < feed.size(); ++i) {
        std::cout << feed[i] << (i + 1 < feed.size() ? ", " : "");
    }
    std::cout << "]\n";
}

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    printFeed("Feed de user 1", twitter.getNewsFeed(1));

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    printFeed("Feed tras seguir a 2 y que publique", twitter.getNewsFeed(1));

    twitter.unfollow(1, 2);
    printFeed("Feed tras dejar de seguir a 2", twitter.getNewsFeed(1));

    return 0;
}
