#include <string>
#include <unordered_map>

class AuthenticationManager {
private:
    int timeToLive;
    std::unordered_map<std::string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(std::string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    void renew(std::string tokenId, int currentTime) {
        if (tokens.count(tokenId)) {
            if (tokens[tokenId] > currentTime) {
                tokens[tokenId] = currentTime + timeToLive;
            } else {
                tokens.erase(tokenId);
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = tokens.begin(); it != tokens.end(); ) {
            if (it->second <= currentTime) {
                it = tokens.erase(it);
            } else {
                count++;
                ++it;
            }
        }
        return count;
    }
};

