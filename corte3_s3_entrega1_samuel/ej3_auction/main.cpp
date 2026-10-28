#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class AuctionSystem {
private:
    // bids[itemId][userId] = bidAmount
    unordered_map<int, unordered_map<int, int>> bids;
    
    // winners[itemId] = set de pares {bidAmount, userId} ordenados de mayor a menor
    // El primer elemento del set será el ganador actual
    unordered_map<int, set<pair<int, int>>> winners;

public:
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        // Si ya existía una oferta, la eliminamos del set de ganadores
        if (bids[itemId].count(userId)) {
            int oldAmount = bids[itemId][userId];
            winners[itemId].erase({oldAmount, userId});
        }
        
        // Agregamos la nueva oferta
        bids[itemId][userId] = bidAmount;
        winners[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        // Eliminamos la oferta vieja
        int oldAmount = bids[itemId][userId];
        winners[itemId].erase({oldAmount, userId});
        
        // Insertamos la nueva
        bids[itemId][userId] = newAmount;
        winners[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int amount = bids[itemId][userId];
        winners[itemId].erase({amount, userId});
        bids[itemId].erase(userId);
        
        // Limpiamos si el item ya no tiene pujas
        if (bids[itemId].empty()) {
            bids.erase(itemId);
            winners.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        if (winners.find(itemId) == winners.end() || winners[itemId].empty()) {
            return -1;
        }
        // El set ordena por defecto de menor a mayor, así que el último es el mayor
        // Pero como usamos pair<int, int>, ordena por amount y luego por userId.
        auto it = prev(winners[itemId].end());
        return it->second; // Retorna el userId
    }
};

int main() {
    AuctionSystem auctionSystem;
    
    cout << "--- Simulacion Ejemplo 1 (LeetCode 3815) ---" << endl;
    
    auctionSystem.addBid(1, 7, 5);
    cout << "addBid(1, 7, 5) -> null" << endl;
    
    auctionSystem.addBid(2, 7, 6);
    cout << "addBid(2, 7, 6) -> null" << endl;
    
    cout << "getHighestBidder(7) -> " << auctionSystem.getHighestBidder(7) << " (Esperado: 2)" << endl;
    
    auctionSystem.updateBid(1, 7, 8);
    cout << "updateBid(1, 7, 8) -> null" << endl;
    
    cout << "getHighestBidder(7) -> " << auctionSystem.getHighestBidder(7) << " (Esperado: 1)" << endl;
    
    auctionSystem.removeBid(2, 7);
    cout << "removeBid(2, 7) -> null" << endl;
    
    cout << "getHighestBidder(7) -> " << auctionSystem.getHighestBidder(7) << " (Esperado: 1)" << endl;
    cout << "getHighestBidder(3) -> " << auctionSystem.getHighestBidder(3) << " (Esperado: -1)" << endl;
    
    return 0;
}
