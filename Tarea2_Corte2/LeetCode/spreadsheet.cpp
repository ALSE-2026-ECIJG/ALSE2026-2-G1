#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Spreadsheet {
private:
    std::vector<std::vector<int>> grid;

    // Función auxiliar para extraer el valor de un operando (puede ser un número o una celda tipo "A1")
    int parseOperand(const std::string& op) {
        // Si el primer carácter es una letra, es una referencia a una celda
        if (op[0] >= 'A' && op[0] <= 'Z') {
            int col = op[0] - 'A';
            int row = std::stoi(op.substr(1)) - 1; // Convertir de 1-indexed a 0-indexed
            return grid[row][col];
        } else {
            // Si es un número literal
            return std::stoi(op);
        }
    }

public:
    Spreadsheet(int rows) {
        // Inicializar la matriz con 26 columnas y 'rows' filas, todas en 0
        grid = std::vector<std::vector<int>>(rows, std::vector<int>(26, 0));
    }
    
    void setCell(std::string cell, int value) {
        int col = cell[0] - 'A';
        int row = std::stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }
    
    void resetCell(std::string cell) {
        int col = cell[0] - 'A';
        int row = std::stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }
    
    int getValue(std::string formula) {
        // La fórmula viene en formato "=X+Y"
        // Quitamos el signo '=' inicial
        std::string expr = formula.substr(1);
        
        // Buscamos el signo '+' para separar los dos operandos
        size_t plusPos = expr.find('+');
        std::string left = expr.substr(0, plusPos);
        std::string right = expr.substr(plusPos + 1);
        
        return parseOperand(left) + parseOperand(right);
    }
};

// Función principal (main) para probar el funcionamiento en la terminal
int main() {
    // Inicializar hoja de cálculo con 3 filas
    Spreadsheet spreadsheet(3);
    
    // getValue("=5+7") -> 12
    std::cout << "getValue(\"=5+7\") (esperado 12): " << spreadsheet.getValue("=5+7") << std::endl;
    
    // setCell("A1", 10)
    spreadsheet.setCell("A1", 10);
    
    // getValue("=A1+6") -> 10 + 6 = 16
    std::cout << "getValue(\"=A1+6\") (esperado 16): " << spreadsheet.getValue("=A1+6") << std::endl;
    
    // setCell("B2", 15)
    spreadsheet.setCell("B2", 15);
    
    // getValue("=A1+B2") -> 10 + 15 = 25
    std::cout << "getValue(\"=A1+B2\") (esperado 25): " << spreadsheet.getValue("=A1+B2") << std::endl;
    
    // resetCell("A1")
    spreadsheet.resetCell("A1");
    
    // getValue("=A1+B2") -> 0 + 15 = 15
    std::cout << "getValue(\"=A1+B2\") tras reset (esperado 15): " << spreadsheet.getValue("=A1+B2") << std::endl;

    return 0;
}

