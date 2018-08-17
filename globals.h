#ifndef TRAB1_GLOBALS_H
#define TRAB1_GLOBALS_H

#include <vector>

#include "point2d.h"
#include "polygonal.h"

enum class Mode {
    drawing_polygon,
    checking_if_inside_polygon
};

const int width = 800;
const int height = 800;

Mode mode = Mode::drawing_polygon;

const point<double> outsider = point<double>(double(width + width), double(height + height)).change_coordinates(width, height);
polygonal<double> polygon;
std::vector<point<double>> points;

#endif //TRAB1_GLOBALS_H
