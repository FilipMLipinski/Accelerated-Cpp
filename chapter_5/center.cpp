#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> center(vector<string> p){
    vector<string>::const_iterator it = p.begin();
    string::size_type max_string = 0;
    while(it!=p.end()){
        max_string = max((*it).size(),max_string);
        it++;
    }
    vector<string> res;
    it = p.begin();
    while(it!=p.end()){
        string s = (*it);
        int n = s.size();
        int pad = max_string-n;
        if(pad%2==0){
            res.push_back(string(pad/2, ' ') + s + string((pad/2) + 1, ' '));
        }
        else{
            res.push_back(string(pad/2 ,' ') + s + string((pad/2), ' '));
        }
        it++;
   }
    return res;
}


void drawPicture(vector<string> p){
    vector<string>::const_iterator it = p.begin();
    while(it!=p.end()){
        cout<< (*it) << endl;
        it++;
    }
}

int main(){
    string line;
    vector<string> picture;
    while(getline(cin, line)){
        if(line=="END") break;
        picture.push_back(line);
    }
    picture = center(picture);
    drawPicture(picture);
    return 0;
}