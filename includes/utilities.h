#ifndef INC_27_4_2_UTILITIES_H
#define INC_27_4_2_UTILITIES_H

#include <cmath>

const double PI = 3.1415;

double getTriangleHeight(double hyp, double cat) {
    return std::sqrt(hyp * hyp -  std::pow(cat / 2, 2));
}

#endif //INC_27_4_2_UTILITIES_H
