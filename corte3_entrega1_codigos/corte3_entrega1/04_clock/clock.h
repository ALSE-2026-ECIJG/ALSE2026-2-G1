#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <iomanip>
#include <sstream>

namespace date_independent {

class clock {
private:
    int total_minutes;

    static int normalize(int minutes) {
        int m = minutes % 1440;
        if (m < 0) {
            m += 1440;
        }
        return m;
    }

public:
    static clock at(int hour, int minute) {
        return clock(hour * 60 + minute);
    }

    explicit clock(int minutes) {
        total_minutes = normalize(minutes);
    }

    clock plus(int minutes) const {
        return clock(total_minutes + minutes);
    }

    clock minus(int minutes) const {
        return clock(total_minutes - minutes);
    }

    bool operator==(const clock& other) const {
        return total_minutes == other.total_minutes;
    }

    bool operator!=(const clock& other) const {
        return !(*this == other);
    }

    operator std::string() const {
        int h = (total_minutes / 60) % 24;
        int m = total_minutes % 60;
        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(2) << h << ":"
           << std::setfill('0') << std::setw(2) << m;
        return ss.str();
    }
};

}  // namespace date_independent

#endif
