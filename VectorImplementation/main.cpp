#include <iostream>
#include "Vector.h"
#include "vector3.h"

int main(void) {
    Vector<Vector3>* myVector = new Vector<Vector3>();

    myVector->PushBack(Vector3(3, 2, 1));
    myVector->EmplaceBack<float>(2, 7, 1);
    myVector->PushBack(Vector3(4, 1, 8));

    std::cout << (*myVector);
}