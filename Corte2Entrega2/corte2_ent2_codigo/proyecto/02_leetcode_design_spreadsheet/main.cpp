#include <iostream>
#include "Spreadsheet.h"

int main() {
    Spreadsheet sheet(3);

    std::cout << "getValue(\"=5+7\") = " << sheet.getValue("=5+7") << "\n";

    sheet.setCell("A1", 10);
    std::cout << "getValue(\"=A1+6\") = " << sheet.getValue("=A1+6") << "\n";

    sheet.setCell("B2", 15);
    std::cout << "getValue(\"=A1+B2\") = " << sheet.getValue("=A1+B2") << "\n";

    sheet.resetCell("A1");
    std::cout << "getValue(\"=A1+B2\") = " << sheet.getValue("=A1+B2") << "\n";

    return 0;
}
