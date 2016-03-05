#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class itemType>
class Triangle : public triangleInterface<itemType> {
private:
    itemType side1, side2, side3;
    bool isATriangle;
    mutable double s, height;
    mutable itemType sides[3];
    mutable std::vector<itemType> threeSides;
public:
    // Default Constructor
    Triangle();

    // Parameterized Constructor
    Triangle(itemType newSide1, itemType newSide2, itemType newSide3);

    // Sets or modifies the sides of the triangle. Ensures that the new sides form a triangle.
    void setSides(itemType newSide1, itemType newSide2, itemType newSide3);

    // Gets the three sides of this triangle. @return a vector containing the values of the sides.
    std::vector<itemType> getSides() const;

    // Computes the area of this triangle. @return This triangle's area.
    itemType getArea() const;

    // Computes the perimeter of this triangle. @return This triangle's perimeter.
    itemType getPerimeter() const;

    // Determines if the triangle is any of these types of triangles. Returns true if it is.
    bool isRightTriangle() const;
    bool isEquilateral() const;
    bool isIsosceles() const;

}; // End Triangle

    // Default Constructor
    template<class itemType>
    Triangle<itemType>::Triangle(){
        side1 = 1;
        side2 = 1;
        side3 = 1;
    }

    // Parameterized Constructor. If the sides do not make a triangle, loops until valid sides are given
    template<class itemType>
    Triangle<itemType>::Triangle(itemType newSide1, itemType newSide2, itemType newSide3){
            side1 = newSide1;
            side2 = newSide2;
            side3 = newSide3;
            if(side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2){
                isATriangle = true;
            }
            if(isATriangle == false)
            cout << "That did not form a triangle. The sum of any two sides of the triangle must be greater than the third." << endl;
    }

    // Same as parameterized constructor
    template<class itemType>
    void Triangle<itemType>::setSides(itemType newSide1, itemType newSide2, itemType newSide3){
        side1 = newSide1;
        side2 = newSide2;
        side3 = newSide3;
        if(side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2){
            isATriangle = true;
        }
        if(isATriangle == false)
            cout << "That did not form a triangle. The sum of any two sides of the triangle must be greater than the third." << endl;
    }

    // Returns three sides as a vector
    template<class itemType>
    std::vector<itemType> Triangle<itemType>::getSides() const{
        sides[0] = side1;
        sides[1] = side2;
        sides[2] = side3;
        threeSides.assign(sides, sides+3);
        return threeSides;
    }

    // Uses Heron's formula, which finds the height, and thus the area, given 3 sides of a triangle
    template<class itemType>
    itemType Triangle<itemType>::getArea() const{
        s = (side1 + side2 + side3)/2;
        height = (2*sqrt(s*(s - side1)*(s - side2)*(s - side3)))/side1;
        return 0.5 * side1 * height;
    }

    // Returns the sum of the three sides
    template<class itemType>
    itemType Triangle<itemType>::getPerimeter() const{
        return side1 + side2 + side3;
    }

    // Checks to see if any combination of sides matches the pythagorean theorem
    template<class itemType>
    bool Triangle<itemType>::isRightTriangle() const{
        if(sqrt(pow(side1, 2) + pow(side2, 2)) == side3 ||
                sqrt(pow(side1, 2) + pow(side3, 2)) == side2 ||
                sqrt(pow(side2, 2) + pow(side3, 2)) == side1){
            return true;
        } else
            return false;
    }

    // Checks if all sides are equal
    template<class itemType>
    bool Triangle<itemType>::isEquilateral() const{
        return side1 == side2 && side2 == side3 ? true : false;
    }

    // Checks if two sides are equal
    template<class itemType>
    bool Triangle<itemType>::isIsosceles() const{
        return side1 == side2 || side1 == side3 || side2 == side3 ? true : false;
    }

#endif //HW3_TRIANGLE_H