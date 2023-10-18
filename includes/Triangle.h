#ifndef INC_27_4_2_TRIANGLE_H
#define INC_27_4_2_TRIANGLE_H

#include <iostream>
#include "Shape.h"
#include "utilities.h"

using std::string;

class Triangle: public Shape {
    double length;
public:
    Triangle(double inX, double inY, double inLength, string inColor = "None"):
            Shape(inX, inY, inX - getTriangleHeight(inLength, inLength) / 2, inY - inLength / 2, std::move(inColor)) {
        length = inLength;
    }

    [[nodiscard]] double getLength() const { return length; }
    [[nodiscard]] double getCenterX() const override { return cX; }
    [[nodiscard]] double getCenterY() const override { return cY; }
    [[nodiscard]] double getArea() const override { return length * length * std::sqrt(3) / 4; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return length; }
    [[nodiscard]] double getRectHeight() const override { return (cX - startX) * 2; }
    [[nodiscard]] string getColor() const override { return color; }
};


#endif //INC_27_4_2_TRIANGLE_H
