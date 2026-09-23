#include <string>
#include <unordered_map>
#include <sstream>

class Spreadsheet {
private:
    int rows;
    std::unordered_map<std::string, int> cells;

    int parseValue(const std::string& token) {
        if (token.empty()) return 0;
        if (isalpha(token[0])) {
            return getCell(token);
        }
        return std::stoi(token);
    }

public:
    Spreadsheet(int height) {
        rows = height;
    }

    void setCell(std::string cell, int value) {
        cells[cell] = value;
    }

    int getCell(std::string cell) {
        if (cells.count(cell)) {
            return cells[cell];
        }
        return 0;
    }

    int getValue(std::string formula) {
        if (formula[0] != '=') {
            return getCell(formula);
        }

        std::string expr = formula.substr(1);
        size_t plusPos = expr.find('+');
        if (plusPos == std::string::npos) {
            return parseValue(expr);
        }

        std::string left = expr.substr(0, plusPos);
        std::string right = expr.substr(plusPos + 1);

        return parseValue(left) + parseValue(right);
    }

    void resetCell(std::string cell) {
        cells.erase(cell);
    }
};

