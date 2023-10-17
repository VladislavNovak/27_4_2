#include <iostream>
#include <cmath>

using std::string;

const double PI = 3.1415;

double getTriangleHeight(double hyp, double cat) {
    return std::sqrt(hyp * hyp -  std::pow(cat / 2, 2));
}

class Figure {
    double cY;
    string color;
protected:
    double cX;
public:
    Figure(double inX, double inY, string inColor) {
        cX = inX;
        cY = inY;
        color = std::move(inColor);
    }
    [[nodiscard]] virtual double getArea() const = 0;
    [[nodiscard]] virtual double getStartX() const = 0;
    [[nodiscard]] virtual double getStartY() const = 0;
    [[nodiscard]] virtual double getRectWidth() const = 0;
    [[nodiscard]] virtual double getRectHeight() const = 0;
};

class Circle: public Figure {
    double radius;
    double startX;
    double startY;
public:
    Circle(double inX, double inY, double inRadius, string inColor = "None"): Figure(inX, inY, std::move(inColor)) {
        radius = inRadius;
        startX = inX - inRadius;
        startY = inY - inRadius;
    }

    [[nodiscard]] double getArea() const override { return PI * radius * radius; }
    // [[nodiscard]] double getArea() const { return atan(1) * 4 * radius; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return radius * 2; }
    [[nodiscard]] double getRectHeight() const override { return radius * 2; }
};

class Rect: public Figure {
    double width;
    double height;
    double startX;
    double startY;
public:
    Rect(double inX, double inY, double inWidth, double inHeight, string inColor = "None"): Figure(inX, inY, std::move(inColor)) {
        width = inWidth;
        height = inHeight;
        startX = inX - width / 2;
        startY = inY - height / 2;
    }

    [[nodiscard]] double getArea() const override { return width * height; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return width; }
    [[nodiscard]] double getRectHeight() const override { return height; }
    [[nodiscard]] bool hasSquare() const { return width == height; }
};

class Triangle: public Figure {
    double length;
    double startX;
    double startY;
    Triangle(double inX, double inY, double inLength, string inColor = "None"): Figure(inX, inY, std::move(inColor)) {
        length = inLength;
        startX = inX - getTriangleHeight(inLength, inLength) / 2;
        startY = inY - inLength / 2;
    }

    [[nodiscard]] double getArea() const override { return length * length * std::sqrt(3) / 4; }
    [[nodiscard]] double getStartX() const override { return startX; }
    [[nodiscard]] double getStartY() const override { return startY; }
    [[nodiscard]] double getRectWidth() const override { return length; }
    [[nodiscard]] double getRectHeight() const override { return (cX - startX) * 2; }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
