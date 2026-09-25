#include <iostream>
#include <vector>
#include <string>

class Spreadsheet {
private:
    std::vector<std::vector<int>> sheet;
public:
    Spreadsheet(int rows, int cols) {
        sheet.resize(rows, std::vector<int>(cols, 0));
    }
    
    void updateCell(int row, int col, int val) {
        if (row >= 0 && row < sheet.size() && col >= 0 && col < sheet[0].size()) {
            sheet[row][col] = val;
        }
    }
    
    int getCell(int row, int col) {
        if (row >= 0 && row < sheet.size() && col >= 0 && col < sheet[0].size()) {
            return sheet[row][col];
        }
        return -1;
    }
};

int main() {
    Spreadsheet mySheet(3, 3);
    mySheet.updateCell(0, 0, 10);
    std::cout << "Celda (0,0): " << mySheet.getCell(0, 0) << std::endl;
    return 0;
}
