#include "clock.h"
#include <iomanip>
#include <sstream>

Clock::Clock(int hour, int minute) {
    normalize(hour * 60 + minute);
}

void Clock::normalize(int minutes) {
    // El día tiene 1440 minutos. Usamos el módulo para dar la vuelta.
    totalMinutes = minutes % 1440;
    if (totalMinutes < 0) {
        totalMinutes += 1440;
    }
}

Clock Clock::add(int minutes) const {
    return Clock(0, totalMinutes + minutes);
}

Clock Clock::subtract(int minutes) const {
    return Clock(0, totalMinutes - minutes);
}

std::string Clock::toString() const {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes;
    return oss.str();
}

bool Clock::operator==(const Clock& other) const {
    return totalMinutes == other.totalMinutes;
}

bool Clock::operator!=(const Clock& other) const {
    return !(*this == other);
}
