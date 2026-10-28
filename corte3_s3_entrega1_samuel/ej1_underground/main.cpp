#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<double, int>> routeMap;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkInMap[id];
        checkInMap.erase(id);
        
        string route = startStation + "->" + stationName;
        double travelTime = t - startTime;
        
        routeMap[route].first += travelTime;
        routeMap[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation;
        auto [totalTime, count] = routeMap[route];
        return totalTime / count;
    }
};

int main() {
    UndergroundSystem undergroundSystem;
    
    // --- Simulación del Ejemplo 1 de LeetCode ---
    cout << "--- Simulacion Ejemplo 1 ---" << endl;
    
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    
    cout << "Promedio Paradise -> Cambridge: " 
         << undergroundSystem.getAverageTime("Paradise", "Cambridge") << endl;
         
    cout << "Promedio Leyton -> Waterloo: " 
         << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;
         
    undergroundSystem.checkIn(10, "Leyton", 24);
    
    cout << "Promedio Leyton -> Waterloo (antes del 3er viaje): " 
         << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;
         
    undergroundSystem.checkOut(10, "Waterloo", 38);
    
    cout << "Promedio Leyton -> Waterloo (con 3er viaje): " 
         << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;

    return 0;
}
