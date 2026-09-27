#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<int> times;
    std::vector<long long> prefix_sums;

public:
    ExamTracker() {}
    
    void record(int time, int score) {
        times.push_back(time);
        long long current_sum = score;
        if (!prefix_sums.empty()) {
            current_sum += prefix_sums.back();
        }
        prefix_sums.push_back(current_sum);
    }
    
    long long totalScore(int startTime, int endTime) {
        if (times.empty()) return 0;
        
        // Encontrar el primer índice cuyo tiempo sea >= startTime
        auto start_it = std::lower_bound(times.begin(), times.end(), startTime);
        // Encontrar el primer índice cuyo tiempo sea > endTime
        auto end_it = std::upper_bound(times.begin(), times.end(), endTime);
        
        int start_idx = std::distance(times.begin(), start_it);
        int end_idx = std::distance(times.begin(), end_it) - 1;
        
        if (start_idx > end_idx || start_idx >= times.size()) {
            return 0;
        }
        
        long long total = prefix_sums[end_idx];
        if (start_idx > 0) {
            total -= prefix_sums[start_idx - 1];
        }
        
        return total;
    }
};

