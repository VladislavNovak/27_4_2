#ifndef INC_27_4_2_CIRCLE_H
#define INC_27_4_2_CIRCLE_H

#include <iostream>
#include "constants.h"
#include "Shape.h"

using std::string;

class Circle: public Shape {
    double radius;
public:
    Circle(double inX, double inY, double inRadius, string inColor = "None"):
            Shape(inX, inY, inX - inRadius, inY - inRadius, std::move(inColor)) {
        radius = inRadius;
    }

    [[nodiscard]] double getRadius() const { return radius; }

    [[nodiscard]] double getCenterX() const override { return cX; }
    [[nodiscard]] double getCenterY() const override { return cY; }
    [[nodiscard]] double getArea() const override { return PI * radius * radius; }
    // [[nodiscard]] double getArea() const { return atan(1) * 4 * radius; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return radius * 2; }
    [[nodiscard]] double getRectHeight() const override { return radius * 2; }
    [[nodiscard]] string getColor() const override { return color; }
};

#endif //INC_27_4_2_CIRCLE_H
