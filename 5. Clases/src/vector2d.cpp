#include "vector2d.h"

// Constructor por defecto
Vector2D::Vector2D(void) {
    x_ = 0.0;
    y_ = 0.0;
}

// Constructor general
Vector2D::Vector2D(double x_val, double y_val) {
    x_ = x_val;
    y_ = y_val;
}

// Constructor de copia
Vector2D::Vector2D(const Vector2D& other) {
    x_ = other.x_;
    y_ = other.y_;
}

// Función add(double, double)
float Vector2D::add(double a, double b) {
    return static_cast<float>(a + b);
}

// Función add(int, int)
int Vector2D::add(int a, int b) {
    return a + b;
}

// Función miembro SetData()
void Vector2D::SetData(void) {
    cout << "Introduzca el valor de X: ";
    cin >> x_;
    cout << "Introduzca el valor de Y: ";
    cin >> y_;
}

// Setter X
void Vector2D::setX(double x_val) {
    x_ = x_val;
}

// Setter Y
void Vector2D::setY(double y_val) {
    y_ = y_val;
}

// Operador miembro + (suma de vectores)
Vector2D Vector2D::operator+(const Vector2D& other) {
    Vector2D suma;
    suma.x_ = x_ + other.x_;
    suma.y_ = y_ + other.y_;
    return suma;
}

// Operador miembro + unario (incrementa ambos componentes)
Vector2D Vector2D::operator+() {
    Vector2D incremento;
    incremento.x_ = x_ + 1;
    incremento.y_ = y_ + 1;
    return incremento;
}

// Operador miembro - (resta de vectores)
Vector2D Vector2D::operator-(const Vector2D& other) {
    Vector2D resta;
    resta.x_ = x_ - other.x_;
    resta.y_ = y_ - other.y_;
    return resta;
}

// Operador miembro * (producto punto)
double Vector2D::operator*(const Vector2D& other) {
    return (x_ * other.x_ + y_ * other.y_);
}

// Operador miembro / (división componente a componente)
Vector2D Vector2D::operator/(const Vector2D& other) {
    Vector2D cociente;
    cociente.x_ = x_ / other.x_;
    cociente.y_ = y_ / other.y_;
    return cociente;
}

// Operador de asignación
Vector2D& Vector2D::operator=(const Vector2D& other) {
    x_ = other.x_;
    y_ = other.y_;
    return *this;
}

// Operador friend == (igualdad)
int operator==(const Vector2D& lhs, const Vector2D& rhs) {
    return (lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_);
}

// Operador friend != (desigualdad)
int operator!=(const Vector2D& lhs, const Vector2D& rhs) {
    return (lhs.x_ != rhs.x_ || lhs.y_ != rhs.y_);
}

// Operador friend << (salida por stream)
ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}

// Display
void Vector2D::display() {
    cout << "(" << x_ << ", " << y_ << ")" << endl;
}