#ifndef GUARD_grade_h
#define GUARD_grade_h
// grade.h
#include <vector>
#include <stdexcept>
#include "median.h"
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
#endif