#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * @class Vector2D
 * @brief Represents a 2D vector and provides operations for vector arithmetic.
 */
class Vector2D {
private:
    /**
     * @brief X component of the vector.
     */
    double x_;

    /**
     * @brief Y component of the vector.
     */
    double y_;

public:
    /**
     * @brief Name associated with the vector.
     */
    string nombre;

    // Constructors

    /**
     * @brief Default constructor for the Vector2D class.
     */
    Vector2D(void);

    /**
     * @brief Constructor with x and y components.
     * @param x_val X component of the vector.
     * @param y_val Y component of the vector (default is 0.0).
     */
    Vector2D(double x_val, double y_val = 0.0);

    /**
     * @brief Copy constructor for the Vector2D class.
     * @param other Another Vector2D object to copy from.
     */
    Vector2D(const Vector2D& other);

    /**
     * @brief Adds two double values.
     * @param a First value.
     * @param b Second value.
     * @return Sum of the two values as a float.
     */
    float add(double a, double b);

    /**
     * @brief Adds two integer values.
     * @param a First value.
     * @param b Second value.
     * @return Sum of the two values as an integer.
     */
    int add(int a, int b);

    // Setters

    /**
     * @brief Sets the data for the vector.
     */
    void SetData(void);

    /**
     * @brief Sets the X component of the vector.
     * @param x_val X component to set.
     */
    void setX(double x_val);

    /**
     * @brief Sets the Y component of the vector.
     * @param y_val Y component to set.
     */
    void setY(double y_val);

    // Getters

    /**
     * @brief Gets the X component of the vector.
     * @return X component of the vector.
     */
    double getX(void) { return x_; }

    /**
     * @brief Gets the Y component of the vector.
     * @return Y component of the vector.
     */
    double getY(void) { return y_; }

    // Operator Overloads

    /**
     * @brief Overloads the addition operator for vectors.
     * @param other Another Vector2D object to add.
     * @return Sum of the two vectors.
     */
    Vector2D operator+ (const Vector2D& other);

    /**
     * @brief Unary plus operator overload.
     * @return The same Vector2D object.
     */
    Vector2D operator+ ();

    /**
     * @brief Overloads the subtraction operator for vectors.
     * @param other Another Vector2D object to subtract.
     * @return Difference of the two vectors.
     */
    Vector2D operator- (const Vector2D& other);

    /**
     * @brief Overloads the multiplication operator for vectors (dot product).
     * @param other Another Vector2D object to multiply.
     * @return Dot product of the two vectors.
     */
    double operator* (const Vector2D& other);

    /**
     * @brief Overloads the division operator for vectors (component-wise).
     * @param other Another Vector2D object to divide by.
     * @return Component-wise quotient of the two vectors.
     */
    Vector2D operator/ (const Vector2D& other);

    /**
     * @brief Overloads the assignment operator for vectors.
     * @param other Another Vector2D object to assign from.
     * @return Reference to the assigned Vector2D object.
     */
    Vector2D& operator= (const Vector2D& other);

    // Comparison Operators

    /**
     * @brief Overloads the equality operator for vectors.
     * @param lhs Left-hand side Vector2D object.
     * @param rhs Right-hand side Vector2D object.
     * @return 1 if the two vectors are equal, 0 otherwise.
     */
    friend int operator== (const Vector2D& lhs, const Vector2D& rhs);

    /**
     * @brief Overloads the inequality operator for vectors.
     * @param lhs Left-hand side Vector2D object.
     * @param rhs Right-hand side Vector2D object.
     * @return 1 if the two vectors are not equal, 0 otherwise.
     */
    friend int operator!= (const Vector2D& lhs, const Vector2D& rhs);

    // Stream Operators

    /**
     * @brief Overloads the insertion operator for output streams.
     * @param os Output stream.
     * @param v Vector2D object to insert into the stream.
     * @return Reference to the output stream.
     */
    friend ostream& operator<< (ostream& os, const Vector2D& v);

    // Additional Functions

    /**
     * @brief Displays the details of the vector.
     */
    void display();

};

#endif