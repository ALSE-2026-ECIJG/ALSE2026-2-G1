#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Twitter {
private:
    long long timeStamp;
    
    // Estructura para almacenar cada tweet con su tiempo y ID
    struct Tweet {
        long long time;
        int tweetId;
        Tweet(long long t, int id) : time(t), tweetId(id) {}
    };

    // Relaciones: Usuario -> Lista de tweets propios
    std::unordered_map<int, std::vector<Tweet>> tweets;
    
    // Relaciones: Usuario -> Conjunto de IDs de usuarios a los que sigue
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(timeStamp++, tweetId));
    }
    
    std::vector<int> getNewsFeed(int userId) {
        // Usamos una cola de prioridad para ordenar los tweets del más reciente al más antiguo
        // Guardamos pares de {time, tweetId}
        std::priority_queue<std::pair<long long, int>> maxHeap;

        // Añadir los tweets propios del usuario
        if (tweets.find(userId) != tweets.end()) {
            for (const auto& tweet : tweets[userId]) {
                maxHeap.push({tweet.time, tweet.tweetId});
            }
        }

        // Añadir los tweets de los usuarios a los que sigue
        if (following.find(userId) != following.end()) {
            for (int followeeId : following[userId]) {
                if (tweets.find(followeeId) != tweets.end()) {
                    for (const auto& tweet : tweets[followeeId]) {
                        maxHeap.push({tweet.time, tweet.tweetId});
                    }
                }
            }
        }

        // Extraer hasta los 10 tweets más recientes
        std::vector<int> res;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
    }
};

// Función principal (main) para probar el funcionamiento en la terminal
int main() {
    Twitter twitter;
    
    // Usuario 1 postea el tweet 5
    twitter.postTweet(1, 5);
    
    // Obtener feed del usuario 1 -> Debería mostrar [5]
    std::vector<int> feed1 = twitter.getNewsFeed(1);
    std::cout << "Feed del usuario 1 (esperado 5): ";
    for (int id : feed1) std::cout << id << " ";
    std::cout << std::endl;
    
    // Usuario 1 sigue al usuario 2
    twitter.follow(1, 2);
    
    // Usuario 2 postea el tweet 6
    twitter.postTweet(2, 6);
    
    // Obtener feed del usuario 1 -> Debería mostrar [6, 5]
    std::vector<int> feed2 = twitter.getNewsFeed(1);
    std::cout << "Feed del usuario 1 tras seguir a 2 (esperado 6 5): ";
    for (int id : feed2) std::cout << id << " ";
    std::cout << std::endl;
    
    // Usuario 1 deja de seguir al usuario 2
    twitter.unfollow(1, 2);
    
    // Obtener feed del usuario 1 -> Debería mostrar [5] nuevamente
    std::vector<int> feed3 = twitter.getNewsFeed(1);
    std::cout << "Feed del usuario 1 tras dejar de seguir a 2 (esperado 5): ";
    for (int id : feed3) std::cout << id << " ";
    std::cout << std::endl;

    return 0;
}
