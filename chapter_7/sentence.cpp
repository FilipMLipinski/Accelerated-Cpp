#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <algorithm>
#include <stack>

using namespace std;

typedef vector<string> rule;
typedef vector<rule> rule_col;
typedef map<string, rule_col> grammar;

bool isBracketed(string s){
    return s.size()>2 && s[0]=='<' && s[s.size()-1]=='>';
}

int randn(int n){
    const int bs = RAND_MAX/n;
    int r;
    do r = rand()/bs;
    while(r>=n);
    return r;
}

void expand(const grammar & g, vector<string> & ret, string s){
    if(!isBracketed(s)){
        ret.push_back(s);
        return;
    }
    auto it = g.find(s);
    if(it==g.end()){
        cout << "empty rule!" << endl;
        return;
    }
    rule_col c = it->second;
    rule r = c[randn(c.size())];
    for(auto rit = r.begin(); rit!=r.end(); rit++){
        expand(g, ret, (*rit));
    }
    return;
}

vector<string> sentence(const grammar & g){
    stack<string> remaining;
    vector<string> ret;
    remaining.push("<sentence>");
    while(!remaining.empty()){
        string curr = remaining.top();
        remaining.pop();
        if(!isBracketed(curr)){
            ret.push_back(curr);
            continue;
        }
        auto it = g.find(curr);
        if(it==g.end()){
            cout << "empty rule!" << endl;
        }
        else{
            rule_col c = it->second;
            rule r = c[randn(c.size())];
            for(auto itr = r.rbegin(); itr!=r.rend(); itr++){
                remaining.push(*itr);
            }
        }
    }
    return ret;
}

vector<string> split(string s){
    auto i = s.begin();
    vector<string> ret;
    while(i!=s.end()){
        i = find_if(i,s.end(), [](const char c){return c!=' ';});
        auto j = i;
        j = find_if(j,s.end(), [](const char c){return c==' ';});
        ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}

void printVector(vector<string> v){
    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout <<endl;
}

int main(){
    ifstream file ("rulebook.txt");
    string line;
    grammar g;
    while(getline(file, line)){
        vector<string> spl = split(line);
        //printVector(spl);
        g[spl[0]].push_back(vector<string>(spl.begin()+1, spl.end())); 
    }
    while(true){
        string s;
        cin >> s;
        if(s!="N"){
            vector<string> sen = sentence(g);
            printVector(sen);
        }
        else return 0;
    }
    return 0;
}