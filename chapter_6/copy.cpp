#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    auto it = v.begin();
    while(it!=v.end()){
        cout << (*it);
        it++;
    }
    cout << endl;
}