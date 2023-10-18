#ifndef INC_27_4_2_RECT_H
#define INC_27_4_2_RECT_H

#include <iostream>
#include "Shape.h"

using std::string;

class Rect: public Shape {
    double width;
    double height;
public:
    Rect(double inX, double inY, double inWidth, double inHeight, string inColor = "None"):
            Shape(inX, inY, inX - inWidth / 2, inY - inHeight / 2, std::move(inColor)) {
        width = inWidth;
        height = inHeight;
    }

    [[nodiscard]] double getCenterX() const override { return cX; }
    [[nodiscard]] double getCenterY() const override { return cY; }
    [[nodiscard]] double getArea() const override { return width * height; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return width; }
    [[nodiscard]] double getRectHeight() const override { return height; }
    [[nodiscard]] string getColor() const override { return color; }
    [[nodiscard]] bool hasSquare() const { return width == height; }
};

#endif //INC_27_4_2_RECT_H
