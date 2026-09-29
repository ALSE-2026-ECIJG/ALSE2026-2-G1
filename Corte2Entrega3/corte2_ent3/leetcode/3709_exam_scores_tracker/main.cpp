#include <iostream>
#include "ExamTracker.h"

int main() {
    // Ejemplo del enunciado de LeetCode 3709
    ExamTracker examTracker;

    examTracker.record(1, 98);
    std::cout << "totalScore(1, 1) = " << examTracker.totalScore(1, 1) << " (esperado 98)" << std::endl;

    examTracker.record(5, 99);
    std::cout << "totalScore(1, 3) = " << examTracker.totalScore(1, 3) << " (esperado 98)" << std::endl;
    std::cout << "totalScore(1, 5) = " << examTracker.totalScore(1, 5) << " (esperado 197)" << std::endl;
    std::cout << "totalScore(3, 4) = " << examTracker.totalScore(3, 4) << " (esperado 0)" << std::endl;
    std::cout << "totalScore(2, 5) = " << examTracker.totalScore(2, 5) << " (esperado 99)" << std::endl;

    return 0;
}
