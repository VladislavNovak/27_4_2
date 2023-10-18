#include <iostream>
#include "includes/Circle.h"
#include "includes/Rect.h"
#include "includes/Triangle.h"

using std::cout;
using std::endl;
using std::string;

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
