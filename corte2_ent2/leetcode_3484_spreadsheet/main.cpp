#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

class Spreadsheet {
private:
    std::unordered_map<std::string, int> cells;

    int parseOperand(const std::string& op) {
        if (op.empty()) return 0;
        if (isdigit(op[0])) {
            return std::stoi(op);
        }
        auto it = cells.find(op);
        return (it != cells.end()) ? it->second : 0;
    }

public:
    Spreadsheet() {}

    void setCell(const std::string& cell, int value) {
        cells[cell] = value;
    }

    void resetCell(const std::string& cell) {
        cells.erase(cell);
    }

    int getValue(const std::string& formula) {
        std::string expr = formula.substr(1);
        size_t plusPos = expr.find('+');
        std::string left = expr.substr(0, plusPos);
        std::string right = expr.substr(plusPos + 1);
        return parseOperand(left) + parseOperand(right);
    }
};

int main() {
    std::cout << "=== LeetCode 3484: Design Spreadsheet ===\n" << std::endl;

    Spreadsheet sheet;

    std::cout << "setCell(\"A1\", 5)" << std::endl;
    sheet.setCell("A1", 5);

    std::cout << "setCell(\"B2\", 10)" << std::endl;
    sheet.setCell("B2", 10);

    std::cout << "getValue(\"=A1+B2\") -> " << sheet.getValue("=A1+B2") << " (esperado 15)" << std::endl;
    std::cout << "getValue(\"=A1+7\")  -> " << sheet.getValue("=A1+7")  << " (esperado 12)" << std::endl;
    std::cout << "getValue(\"=3+4\")   -> " << sheet.getValue("=3+4")   << " (esperado 7)"  << std::endl;

    std::cout << "\nresetCell(\"A1\")" << std::endl;
    sheet.resetCell("A1");

    std::cout << "getValue(\"=A1+B2\") -> " << sheet.getValue("=A1+B2") << " (esperado 10)" << std::endl;
    std::cout << "getValue(\"=A1+7\")  -> " << sheet.getValue("=A1+7")  << " (esperado 7)"  << std::endl;

    std::cout << "\n=== Fin de las pruebas ===" << std::endl;
    return 0;
}
