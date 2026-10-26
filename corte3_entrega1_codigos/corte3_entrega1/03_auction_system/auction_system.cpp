#include <unordered_map>
#include <set>
#include <utility>

class AuctionSystem {
private:
    // Por cada item: conjunto ordenado de pares (monto, userId).
    // El ultimo elemento es el mejor postor (mayor monto, y en empate mayor userId).
    std::unordered_map<int, std::set<std::pair<int, int>>> itemBids;

    // Indice userId -> (itemId -> monto), para saber el monto anterior de una puja.
    std::unordered_map<int, std::unordered_map<int, int>> userBids;

public:
    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        // Si el usuario ya tenia una puja en este item, se borra el par viejo.
        if (userBids.count(userId) && userBids[userId].count(itemId)) {
            int oldAmount = userBids[userId][itemId];
            itemBids[itemId].erase({oldAmount, userId});
        }

        userBids[userId][itemId] = bidAmount;
        itemBids[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = userBids[userId][itemId];

        itemBids[itemId].erase({oldAmount, userId});

        userBids[userId][itemId] = newAmount;
        itemBids[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int oldAmount = userBids[userId][itemId];

        itemBids[itemId].erase({oldAmount, userId});
        userBids[userId].erase(itemId);
    }

    int getHighestBidder(int itemId) {
        if (!itemBids.count(itemId) || itemBids[itemId].empty()) {
            return -1;
        }

        auto highest = *itemBids[itemId].rbegin();
        return highest.second;
    }
};
