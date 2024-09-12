#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

string concat(vector<string> ss){
    string t = "";
    return accumulate(ss.begin(), ss.end(), string(0, ' '));
}

int main(){
    vector<string> ss = {"hello", "from", "the moon"};
    cout << concat(ss) << endl;
}