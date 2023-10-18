#include <iostream>
#include <vector>
#include "includes/constants.h"
#include "includes/utilities.h"
#include "includes/Circle.h"
#include "includes/Rect.h"
#include "includes/Triangle.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::vector<std::string> mainMenu = { "circle", "rectangle", "square", "triangle", "exit" };

    vector<Circle*> circles;
    vector<Rect*> rectangles;
    vector<Triangle*> triangles;

    while (true) {
        std::cout << "--- Main menu ---" << std::endl;
        int command = selectMenuItem(mainMenu);

        if (command != static_cast<int>(Menu::EXIT)) {
            string color = putLineString("Enter color");
            double centerByX = putNumeric({}, {}, "center by X");
            double centerByY = putNumeric({}, {}, "center by Y");

            if (command == static_cast<int>(Menu::CIRCLE)) {
                double radius = putNumeric({MIN_MAX}, {}, "radius");
                auto* circle = new Circle(centerByX, centerByY, radius, color);
                circles.emplace_back(circle);
            }
            else if (command == static_cast<int>(Menu::RECT) || command == static_cast<int>(Menu::SQUARE)) {
                double width = putNumeric({MIN_MAX}, {}, "width");
                double height = (command == static_cast<int>(Menu::RECT)) ? putNumeric({MIN_MAX}, {}, "height") : width;
                auto* rect = new Rect(centerByX, centerByY, width, height, color);
                rectangles.emplace_back(rect);
            }
            else if (command == static_cast<int>(Menu::TRIANGLE)) {
                double length = putNumeric({MIN_MAX}, {}, "length of side");
                auto* item = new Triangle(centerByX, centerByY, length, color);
                triangles.emplace_back(item);
            }

        }
        else {
            std::cout << "Menu --> exit mode -->" << std::endl;
            break;
        }
    }

    if (!rectangles.empty()) {
        for (auto &item : rectangles) {
            cout << (item->hasSquare() ? "Square" : "Triangle:") << endl;
            cout << "   - center by x/y               :" << item->getCenterX() << "/" << item->getCenterY() << endl;
            cout << "   - color                       :" << item->getColor() << endl;
            cout << "   - area                        :" << item->getArea() << endl;
            cout << "   - rectangle ->" << endl;
            cout << "      - starting point by x/y    :" << item->getStartX() << "/" << item->getStartY() << endl;
            cout << "      - width/height             :" << item->getRectWidth() << "/" << item->getRectHeight() << endl;

            delete item;
            item = nullptr;
        }
        triangles.clear();
    }
    if (!circles.empty()) {
        for (auto &item : circles) {
            cout << "Circle:" << endl;
            cout << "   - center by x/y               :" << item->getCenterX() << "/" << item->getCenterY() << endl;
            cout << "   - radius                      :" << item->getRadius() << endl;
            cout << "   - color                       :" << item->getColor() << endl;
            cout << "   - area                        :" << item->getArea() << endl;
            cout << "   - circumscribing rectangle ->" << endl;
            cout << "      - starting point by x/y    :" << item->getStartX() << "/" << item->getStartY() << endl;
            cout << "      - width/height             :" << item->getRectWidth() << "/" << item->getRectHeight() << endl;

            delete item;
            item = nullptr;
        }
        triangles.clear();
    }
    if (!triangles.empty()) {
        for (auto &item : triangles) {
            cout << "Triangle:" << endl;
            cout << "   - center by x/y               :" << item->getCenterX() << "/" << item->getCenterY() << endl;
            cout << "   - length of side              :" << item->getLength() << "x3" << endl;
            cout << "   - color                       :" << item->getColor() << endl;
            cout << "   - area                        :" << item->getArea() << endl;
            cout << "   - circumscribing rectangle ->" << endl;
            cout << "      - starting point by x/y    :" << item->getStartX() << "/" << item->getStartY() << endl;
            cout << "      - width/height             :" << item->getRectWidth() << "/" << item->getRectHeight() << endl;

            delete item;
            item = nullptr;
        }
        triangles.clear();
    }

    cout << "See you later!" << endl;

    return 0;
}
