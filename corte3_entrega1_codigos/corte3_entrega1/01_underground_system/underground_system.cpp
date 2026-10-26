#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<int, int>> viajes;

public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        string inicio = checkIns[id].first;
        int tiempoInicio = checkIns[id].second;

        string ruta = inicio + "-" + stationName;
        int duracion = t - tiempoInicio;

        viajes[ruta].first += duracion;
        viajes[ruta].second++;

        checkIns.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string ruta = startStation + "-" + endStation;

        return (double)viajes[ruta].first / viajes[ruta].second;
    }
};
