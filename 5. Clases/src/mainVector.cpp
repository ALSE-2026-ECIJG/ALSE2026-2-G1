#include "include/vector2d.h"

int main() {
    Vector2D v1(3, 4), v2(1, 2);
    Vector2D *v_ptr;
    v1.display();
    v2.display();
    v2.setX(10);
    v_ptr=&v2;
    v_ptr->setX(3);
    cout<<v1<<endl;

    Vector2D sum = v1 + v2;
    sum.display();

    return 0;
}