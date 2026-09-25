#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> grid;

    int parseOperand(const string& op) {
        if (op.empty()) return 0;

        if (isdigit(op[0])) {
            return stoi(op);
        }

        if (grid.count(op)) {
            return grid[op];
        }
        return 0;
    }

public:
    Spreadsheet(int rows) {
        grid.clear();
    }

    void setCell(string cell, int value) {
        grid[cell] = value;
    }

    void resetCell(string cell) {
        grid.erase(cell);
    }

    int getValue(string formula) {
        string expr = formula.substr(1);

        size_t plusPos = expr.find('+');

        string leftOp = expr.substr(0, plusPos);
        string rightOp = expr.substr(plusPos + 1);

        return parseOperand(leftOp) + parseOperand(rightOp);
    }
};

#endif
