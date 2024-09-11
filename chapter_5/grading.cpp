#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "split.h"
using namespace std;

struct StudentInfo{
    string name;
    double grade;
};

typedef vector<StudentInfo> StudentList;

StudentInfo extractInfo(string l){
    StudentInfo student;
    vector<string> spl = split(l);
    student.name = spl[0];
    double total = 0;
    double count = 0;
    for(int i = 1; i < spl.size(); i++){
        count++;
        total+=stod(spl[i]);
    }
    student.grade = total/count;
    return student;
}

// works for both vector and list
void printStudents(StudentList students, string::size_type max_name){
    for(StudentList::const_iterator it = students.begin();
    it != students.end(); it++){
        cout << string(max_name - (*it).name.size(), ' ') 
        << (*it).name << ": "<< (*it).grade << endl;
    }
}

// version that works with list and vector
StudentList extractFails(StudentList & students, double thresh){
    StudentList fails;
    StudentList::iterator it = students.begin();
    while(it!=students.end()){
        if((*it).grade < thresh){
            fails.push_back(*it);
            it = students.erase(it);
        }
        else{
            it++;
        }
    }
    return fails;
}

int main(){
    clock_t begin = clock();
    ifstream file;
    int count = 10000;
    file.open("students_" + to_string(count) + ".txt");
    string line;
    StudentList students;
    string::size_type max_name = 0;
    while(getline( file, line)){
        StudentInfo student = extractInfo(line);
        students.push_back(student);
        max_name = max(student.name.size(), max_name);
    }
    StudentList fails = extractFails(students, 60);
    clock_t end = clock();
    // cout << "PASSED: "<<endl;
    // printStudents(students, max_name);
    // cout << "FAILED: "<<endl;
    // printStudents(fails, max_name);
    std::cout << "Elapsed(s)=" << double(end-begin)/CLOCKS_PER_SEC << std::endl;
    return 0;
}