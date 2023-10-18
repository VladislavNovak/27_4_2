#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

const double PI = 3.1415;

double getTriangleHeight(double hyp, double cat) {
    return std::sqrt(hyp * hyp -  std::pow(cat / 2, 2));
}

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

int main() {
    auto* triangle = new Triangle(0,0,10,"black");
    cout << "Triangle options:" << endl;
    cout << "   - center by x/y               :" << triangle->getCenterX() << "/" << triangle->getCenterY() << endl;
    cout << "   - length of side              :" << triangle->getLength() << "x3" << endl;
    cout << "   - color                       :" << triangle->getColor() << endl;
    cout << "   - area                        :" << triangle->getArea() << endl;
    cout << "   - circumscribing rectangle ->" << endl;
    cout << "      - starting point by x/y    :" << triangle->getStartX() << "/" << triangle->getStartY() << endl;
    cout << "      - width/height             :" << triangle->getRectWidth() << "/" << triangle->getRectHeight() << endl;

    delete triangle;
    triangle = nullptr;

    return 0;
}
