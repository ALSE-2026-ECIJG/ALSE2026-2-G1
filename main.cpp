#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double calcularDistanciaMasCercana(
    Point puntos[],
    int n,
    const Point &pUsuario,
    int &indiceMasCercano)
{
    double distanciaMinima = sqrt(
        pow(puntos[0].x - pUsuario.x, 2) +
        pow(puntos[0].y - pUsuario.y, 2)
    );

    indiceMasCercano = 0;

    for (int i = 1; i < n; i++)
    {
        double distancia = sqrt(
            pow(puntos[i].x - pUsuario.x, 2) +
            pow(puntos[i].y - pUsuario.y, 2)
        );

        if (distancia < distanciaMinima)
        {
            distanciaMinima = distancia;
            indiceMasCercano = i;
        }
    }

    return distanciaMinima;
}

int main()
{
    int n;

    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    Point puntos[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nPunto " << i << endl;

        cout << "Ingrese x: ";
        cin >> puntos[i].x;

        cout << "Ingrese y: ";
        cin >> puntos[i].y;
    }

    Point pUsuario;

    cout << "\nIngrese las coordenadas del punto de referencia:" << endl;

    cout << "x: ";
    cin >> pUsuario.x;

    cout << "y: ";
    cin >> pUsuario.y;

    int indiceMasCercano;

    double distanciaMinima = calcularDistanciaMasCercana(
        puntos,
        n,
        pUsuario,
        indiceMasCercano
    );

    cout << "\n--- RESULTADO ---" << endl;
    cout << "Punto mas cercano: " << indiceMasCercano << endl;

    cout << "Coordenadas: ("
         << puntos[indiceMasCercano].x << ", "
         << puntos[indiceMasCercano].y << ")" << endl;

    cout << "Distancia minima: " << distanciaMinima << endl;

    return 0;
}
