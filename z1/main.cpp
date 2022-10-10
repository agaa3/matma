#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

int main()
{
    //1
    Vector v1(1, 2, 3);
    Vector v2(3, 2, 1);
    v1.add(v2);
    Vector v3(1, 2, 3);
    Vector v4(3, 2, 1);
    v4.add(v3);
    cout << "1. " << endl << "(" << v1.x << ", " << v1.y <<
    ", " << v1.z << ")" << endl;
    cout << "(" << v4.x << ", " << v4.y <<
    ", " << v4.z << ")" << endl;
    //2
    Vector v5(0, 3, 0);
    Vector v6(5, 5, 0);
    float dotProduct = v5.dotProduct(v6); //u*v=|u||v|cosalfa
    float lenv5 = v5.length();
    float lenv6 = v6.length();
    dotProduct /= (lenv5*lenv6);
    float rad = acos(dotProduct); //radians
    float angle = rad * (180.0 / M_PI);

    cout << "2." << endl << angle << " stopni" << endl;
    //3
    Vector v7(4, 5, 1);
    Vector v8(4, 1, 3);
    Vector cross = v7.cross(v8);
    cout << "3. " << endl << "(" << cross.x << ", " << cross.y <<
    ", " << cross.z << ")" << endl;

    //4
    cross.normalize();
    cout << "3. " << endl << "(" << cross.x << ", " << cross.y <<
    ", " << cross.z << ")" << endl;

    //5
    return 0;
}
