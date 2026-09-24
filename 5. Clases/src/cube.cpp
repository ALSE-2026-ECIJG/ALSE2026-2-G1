#include "cube.h"
Cube::Cube(double len)
{
    if (len > 0)
    {
        length = len;
    }
    else
    {
        length = 1.0; // Default length if invalid
    }
}
Cube::Cube()
{
    length = 1.0;
}
double Cube::getVolume() const
{
    return length * length * length;
}
double Cube::getSurfaceArea() const{
    return 6 * length * length;
}
void Cube::setLength(double len){
    if (len > 0)
    {
        length = len;
    }
}
double Cube::getLength() const{
    return length;
}
Cube::~Cube() {
    // Destructor logic if needed
    std::cout<<"Cube destructor called"<<std::endl;
}