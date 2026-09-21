#ifndef __SHAPE3D_H__
#define __SHAPE3D_H__

/**
 * @file Shape3d.h
 * @brief Abstract base class for 3D shapes.
 *
 * This header defines the Shape3D interface which provides two
 * pure virtual methods that all concrete 3D shape classes must
 * implement: volume and surface area calculations.
 */

/**
 * @class Shape3D
 * @brief Interface for three-dimensional geometric shapes.
 *
 * Shape3D is an abstract base class that requires derived classes
 * to implement methods for computing the volume and the surface area
 * of a shape. It defines a virtual destructor to ensure proper
 * cleanup of derived objects through base pointers.
 */
class Shape3D {
public:
    /**
     * @brief Compute the volume of the shape.
     *
     * This is a pure virtual function. Derived classes must override
     * this method and return the volume in the appropriate units.
     *
     * @return Volume as a double.
     */
    virtual double getVolume() const = 0; // Pure virtual function

    /**
     * @brief Compute the surface area of the shape.
     *
     * Pure virtual method that should be implemented by concrete
     * shape classes. The returned value represents the total surface
     * area.
     *
     * @return Surface area as a double.
     */
    virtual double getSurfaceArea() const = 0;

    /**
     * @brief Virtual destructor.
     *
     * Ensures that destructors of derived classes are called when an
     * object is deleted through a pointer to Shape3D.
     */
    virtual ~Shape3D() {}
};

#endif // __SHAPE3D_H__