#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string randString(){
    string res = "";
    int n = rand() % 5 + 4;
    for(int i = 0; i<n;i++){
        res += 'a' + rand()%26;
    }
    return res;
}
int main(){
    int count = 100000;
    ofstream file;
    file.open("students_" + to_string(count) + ".txt");
    for(int i =0; i<count; i++){
        file << randString() + " ";
        int grades = rand() % 5 + 4;
        for(int j = 0; j<grades; j++){
            file << rand()%90 + 10 << " ";
        } 
        file << endl;
    }
    return 0;
}