#include <iostream>
#include "Vector.h"
#include "Matrix4.h"
#include "Quaternion.h"
#include "Line.h"
#include "Plane.h"
#include "Camera.h"

const int SIZE = 60;
int main() {

    //bryla2x2x2
    float cubeSize = 2;
    Plane p_front = Plane(Vector(-cubeSize/2, -cubeSize/2, cubeSize/2), Vector(0, 0, 1));
    Plane p_back = Plane(Vector(-cubeSize/2, -cubeSize/2, -cubeSize/2), Vector(0, 0, -1));
    Plane p_left = Plane(Vector(-cubeSize/2, -cubeSize/2, cubeSize/2), Vector(-1, 0, 0));
    Plane p_right = Plane(Vector(cubeSize/2, -cubeSize/2, cubeSize/2), Vector(1, 0, 0));
    Plane p_bottom = Plane(Vector(-cubeSize/2, -cubeSize/2, cubeSize/2), Vector(0, -1, 0));
    Plane p_up = Plane(Vector(-cubeSize/2, cubeSize/2, cubeSize/2), Vector(0, 1, 0));

    char tab[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            tab[i][j] = '.';
        }
    }

    float width = 2;

    Camera cam = Camera(3);
    cam.rotateY(45);
    std::cout << "pos: " << cam.position << ", dir: " << cam.direction << ", up: " << cam.up <<", right: " << cam.right << std::endl;

    cam.rotateX(45);
    std::cout << "pos: " << cam.position << ", dir: " << cam.direction << ", up: " << cam.up <<", right: " << cam.right << std::endl;

    Vector rightDirectionView = cam.direction.cross(cam.up);
    Line ray = Line(cam.position, cam.direction);
    Vector point;
    bool isCrossing = false;
    for(int i =0; i< SIZE; i++) { //wiersze
        for(int j =0; j< SIZE; j++) { //kolumny
            ray.direction =
                    cam.direction +
                    Vector((j-SIZE/2)*(width / 60)*rightDirectionView.x,
                           (j - SIZE/2)*(width / 60)*rightDirectionView.y,
                           (j - SIZE/2)*(width / 60)*rightDirectionView.z) +
                    Vector((SIZE/2 - i)*width/60*cam.up.x,
                           (SIZE/2 - i)*width/60*cam.up.y,
                           (SIZE/2 - i)*width/60*cam.up.z);; //od górnego lewego rogu
            if(Plane::isLineAndPlaneCrossing(ray, p_front)) {
                point = Plane::crossingOfLineAndPlane(ray, p_front);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }
            }
            if(Plane::isLineAndPlaneCrossing(ray, p_back)) {
                point = Plane::crossingOfLineAndPlane(ray, p_back);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }
            }
            if(Plane::isLineAndPlaneCrossing(ray, p_left)) {
                point = Plane::crossingOfLineAndPlane(ray, p_left);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }

            }
            if(Plane::isLineAndPlaneCrossing(ray, p_right)) {
                point = Plane::crossingOfLineAndPlane(ray, p_right);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }
            }
            if(Plane::isLineAndPlaneCrossing(ray, p_up)) {
                point = Plane::crossingOfLineAndPlane(ray, p_up);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }
            }
            if(Plane::isLineAndPlaneCrossing(ray, p_bottom)) {
                point = Plane::crossingOfLineAndPlane(ray, p_bottom);
                if(point.x <= cubeSize/2 && point.y <= cubeSize/2 && point.z <= cubeSize / 2
                   && point.x >= -cubeSize/2 && point.y >= -cubeSize/2 && point.z >= -cubeSize / 2) {
                    isCrossing = true;
                }
            }
            if(isCrossing) {
                tab[i][j] = '0';
            } else {
                tab[i][j] = '.';
            }
            isCrossing = false;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            std::cout << tab[i][j] << " ";
        }
    }
    std::cout << "pos: " << cam.position << ", dir: " << cam.direction << ", up: " << cam.up << std::endl;
    std::cout << rightDirectionView;
    return 0;
}