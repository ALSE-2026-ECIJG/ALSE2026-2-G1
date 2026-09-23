#include <iostream>
#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<long long> times;
    std::vector<long long> prefix;

public:
    ExamTracker() {}

    void record(int time, int score) {
        times.push_back(time);
        long long prev = prefix.empty() ? 0 : prefix.back();
        prefix.push_back(prev + score);
    }

    long long totalScore(int startTime, int endTime) {
        auto leftIt = std::lower_bound(times.begin(), times.end(), (long long)startTime);
        auto rightIt = std::upper_bound(times.begin(), times.end(), (long long)endTime);

        int left = leftIt - times.begin();
        int right = rightIt - times.begin();

        if (left >= right) return 0;

        long long sum = prefix[right - 1];
        if (left > 0) sum -= prefix[left - 1];
        return sum;
    }
};

int main() {
    std::cout << "=== LeetCode 3709: Exam Score Tracker ===\n" << std::endl;

    ExamTracker tracker;

    tracker.record(1, 98);
    std::cout << "record(1, 98)" << std::endl;
    std::cout << "totalScore(1, 1) = " << tracker.totalScore(1, 1) << std::endl;

    tracker.record(5, 99);
    std::cout << "record(5, 99)" << std::endl;
    std::cout << "totalScore(1, 3) = " << tracker.totalScore(1, 3) << std::endl;
    std::cout << "totalScore(1, 5) = " << tracker.totalScore(1, 5) << std::endl;
    std::cout << "totalScore(3, 4) = " << tracker.totalScore(3, 4) << std::endl;
    std::cout << "totalScore(2, 5) = " << tracker.totalScore(2, 5) << std::endl;

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
