#ifndef INC_27_4_2_SHAPE_H
#define INC_27_4_2_SHAPE_H

#include <iostream>

using std::string;

class Shape {
protected:
    double cY;
    double cX;
    double startX;
    double startY;
    string color;
public:
    Shape(double inX, double inY, double inStartX, double inStartY, string inColor) {
        cX = inX;
        cY = inY;
        startX = inStartX;
        startY = inStartY;
        color = std::move(inColor);
    }
    [[nodiscard]] virtual double getArea() const = 0;
    [[nodiscard]] virtual double getCenterX() const = 0;
    [[nodiscard]] virtual double getCenterY() const = 0;
    [[nodiscard]] virtual double getStartX() const = 0;
    [[nodiscard]] virtual double getStartY() const = 0;
    [[nodiscard]] virtual double getRectWidth() const = 0;
    [[nodiscard]] virtual double getRectHeight() const = 0;
    [[nodiscard]] virtual string getColor() const = 0;
};

#endif //INC_27_4_2_SHAPE_H
