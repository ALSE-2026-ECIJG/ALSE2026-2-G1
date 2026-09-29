#ifndef EXAM_TRACKER_H
#define EXAM_TRACKER_H

#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<int> times;
    std::vector<long long> prefixScores;

public:
    ExamTracker() {
        prefixScores.push_back(0);
    }

    void record(int time, int score) {
        times.push_back(time);
        prefixScores.push_back(prefixScores.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        if (times.empty()) return 0;

        auto it1 = std::lower_bound(times.begin(), times.end(), startTime);
        int idx1 = std::distance(times.begin(), it1);

        auto it2 = std::upper_bound(times.begin(), times.end(), endTime);
        int idx2 = std::distance(times.begin(), it2);

        return prefixScores[idx2] - prefixScores[idx1];
    }
};

#endif // EXAM_TRACKER_H
