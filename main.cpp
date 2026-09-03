#include <iostream>
#include <vector>
#include <iomanip>

struct Point {
    double x;
    double y;
};

Point calcularCentroide(const std::vector<Point>& puntos) {
    Point centroide = {0.0, 0.0};
    if (puntos.empty()) return centroide;

    double sumaX = 0.0;
    double sumaY = 0.0;

    for (const auto& p : puntos) {
        sumaX += p.x;
        sumaY += p.y;
    }

    centroide.x = sumaX / puntos.size();
    centroide.y = sumaY / puntos.size();

    return centroide;
}

int main() {
    int n;
    std::cout << "--- Calculadora de Centroide ---" << std::endl;
    std::cout << "Ingrese la cantidad de puntos: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Cantidad invalida." << std::endl;
        return 1;
    }

    std::vector<Point> puntos(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Punto " << i + 1 << " (x y): ";
        std::cin >> puntos[i].x >> puntos[i].y;
    }

    Point centroide = calcularCentroide(puntos);

    std::cout << "\n====================================" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "El centroide del conjunto de puntos es:" << std::endl;
    std::cout << "X: " << centroide.x << " | Y: " << centroide.y << std::endl;
    std::cout << "====================================" << std::endl;

    return 0;
}
