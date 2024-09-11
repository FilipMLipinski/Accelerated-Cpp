#include "split.h"
using namespace std;
vector<string> split(string s){
    vector<string> res;
    int i = 0;
    while(i!=s.size()){
        while(i!=s.size() && isspace(s[i])) ++i;
        int j = i;
        while(j!=s.size() && !isspace(s[j])) ++j;
        if(i!=j){
            res.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return res;
}