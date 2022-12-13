#include <iostream>
#include "Vector.h"
#include "Matrix4.h"
#include "Quaternion.h"

int main() {
    //1
    //A -> wektor: (3, 1, 5), P0: [-2, 4, 0]
    //B -> wektor: (1, -5, 3), P0: [-2, 4, 0]
    Vector vDir1_1 = Vector(3, 1, 5);
    Vector p1_1 = Vector(-2, 4, 0);
    Vector vDir2_1 = Vector(1, -5, 3);
    Vector p2_1 = Vector(-2, 4, 0);

    Vector odp1 = p1_1.crossingOfTwoLines(p1_1, vDir1_1, p2_1, vDir2_1);
    std::cout << "zadanie 1: " << odp1 << std::endl;

    //2
    float dotProd_2 = vDir1_1.dotProduct(vDir2_1);
    dotProd_2 /= vDir1_1.length();
    dotProd_2 /= vDir2_1.length();
    float odp2 = acos(dotProd_2)*180/M_PI;
    std::cout <<"zadanie 2: " << odp2 << " stopni" << std::endl;

    //z3
    //prosta: v1: (3, -1, 2) p0_3: [-2, 2, -1]
    Vector vDir1_3 = Vector(3, -1, 2);
    Vector p0_3 = Vector(-2, 2, -1);
    //plaszczyzna: n_3: (2, 3, 3), p0_3: (4, 0, 0)
    Vector n_3 = Vector(2, 3, 3);
    Vector q0_3 = Vector(4, 0, 0);
    int t_3 = (n_3 * (-1)).dotProduct((p0_3 - q0_3));
    t_3 = t_3 / (n_3.dotProduct(vDir1_3));
    Vector odp3 = Vector(p0_3.x + vDir1_3.x * t_3, p0_3.y + vDir1_3.y * t_3, p0_3.z + vDir1_3.z * t_3);
    std::cout <<"zadanie 3: " << odp3 << std::endl;

    //z4 - kat miedzy normalną a wektorem kierunkowym
    float dotProd_4 = n_3.dotProduct(vDir1_3);
    dotProd_4 /= vDir1_3.length();
    dotProd_4 /= n_3.length();
    float alfa_4 = acos(dotProd_4);
    float odp4 = (alfa_4) * 180 / M_PI;
    std::cout <<"zadanie 4: " << odp4 << " stopni" << std::endl;

    //z5
    //plaszczyzna1: n_3: (2, -1, 1) p0_3: [4, 0, 0]
    //plaszczyzna2: n_3: (4, 3, 1), p0_3: [0, 0, -14]

    Vector n1_5 = Vector(2, -1, 1);
    Vector q1_5 = Vector(4, 1, 1);
    Vector n2_5 = Vector(4, 3, 1);
    Vector q2_5 = Vector(1, 1, -21);

    Vector vDir1_5 = n1_5.cross(n2_5);
    float Divisior = vDir1_5.length()*vDir1_5.length();
    if (Divisior != 0.0)
    {
        double D1 = (q1_5*(-1)).dotProduct(n1_5); // -8
        double D2 = (q2_5*(-1)).dotProduct(n2_5); // 14

        Vector p0_5 = ((vDir1_5.cross(n2_5) * D1) + (n1_5.cross(vDir1_5) * D2)) / Divisior;
        std::cout << "zadanie 5 v: " << vDir1_5 <<
                  " p0: "<< p0_5 << std::endl;
    }
    else
    {
        std::cout << "Plaszczyzny sie nie przecinaja." << std::endl;
    }

    //z6 kat miedzy normalnymi
    float dotProd_6 = n1_5.dotProduct(n2_5);
    dotProd_6 /= n1_5.length();
    dotProd_6 /= n2_5.length();
    float alfa_6 = acos(dotProd_6);
    float odp6 = (alfa_6) * 180 / M_PI;
    std::cout <<"zadanie 6: " << odp6 << " stopni" << std::endl;

    //z7 odcinki
    Vector a1_7 = Vector(5, 5, 4);
    Vector a2_7 = Vector(10, 10, 6);
    Vector b1_7 = Vector(5, 5, 5);
    Vector b2_7 = Vector(10, 10, 3);
    Vector odp7 = a1_7.crossingOfTwoSegments(a1_7, a2_7, b1_7, b2_7);
    std::cout <<"zadanie 7: " << odp7 << std::endl;

    //z8
    //sfera C: (0, 0, 0), r=sqrt(26)
    //prosta p1: (3, -1, -2), p2 (5, 3, -4)
    Vector c_8 = Vector(0, 0, 0);
    Vector p1_8 = Vector(3, -1, -2);
    Vector p2_8 = Vector(5, 3, -4);
    Vector v_8 = p2_8 - p1_8;
    float r = sqrt(26);

    Vector w_8 = c_8 - p1_8;
    Vector vJedn_8 = v_8.normalize();
    float przypr1 = w_8.dotProduct(vJedn_8);
    float przeciwpr = w_8.length();
    float przypr2 = sqrt(przeciwpr*przeciwpr - przypr1* przypr1);
    if (przypr2 < r) {
        std::cout << "zadanie 8: Prosta przecina sfere (2 punkty przeciecia):";
        float d = sqrt(r*r - (przeciwpr*przeciwpr - przypr1* przypr1));
        Vector x1_8 = p1_8 + vJedn_8 * (przypr1 - d);
        Vector x2_8 = p1_8 + vJedn_8 * (przypr1 + d);

        x1_8.z = round(x1_8.z);
        std::cout << x1_8 << ", " << x2_8 << std::endl;

    } else if ( przypr2 == r) {
        std::cout << "zadanie 8: Prosta jest styczna do sfery." << std::endl;
        Vector x0_8 = p1_8 + vJedn_8 * przypr1;
    } else {
        std::cout << "Prosta nie przecina sfery." << std::endl;
    }


    return 0;
}