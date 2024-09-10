#ifndef GUARD_Student_info
#define GUARD_Student_info
// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include "grade.h"
struct Student_info {
    std::string name;
    double midterm, final, final_grade;
    std::vector<double> homework;
};
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif