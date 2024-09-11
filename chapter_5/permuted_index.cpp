#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "split.h"
using namespace std;
string::size_type max_phrase;
void printBag(vector<pair<vector<string>, int>> bag){
    for(int i = 0; i < bag.size(); i++){
        vector<string> words = (bag[i]).first;
        for(string w:words){
            cout << w << " ";
        }
        cout << bag[i].second << endl;
    }
}

string indexify(const pair<vector<string>, int> & entry){
    int n = entry.first.size();
    int k = entry.second;
    string res;
    for(int i = k; i<n; i++){
        res += entry.first[i] + " ";
    }
    if(k==0){
        return string(max_phrase, ' ') + "   " + res;
    }
    res = string(max_phrase - res.size(), ' ') + res + "   ";
    for(int i = 0; i<k; i++){
        res+=entry.first[i] + " ";
    }
    return res;
}

void permuted_index(vector<string> phrases){
    vector<pair<vector<string>, int>> bag;
    for(vector<string>::iterator it = phrases.begin(); it!=phrases.end(); it++){
        vector<string> phrase = split(*it);
        for(int i = 0; i<phrase.size(); i++){
            vector<string> permutation(phrase.size());
            for(int j=0; j<phrase.size(); j++){
                permutation[(i+j)%phrase.size()] = phrase[j];
            }
            bag.push_back({permutation, i});
        }
    }
    sort(bag.begin(), bag.end());
    for(int i = 0; i<bag.size(); i++){
        cout << indexify(bag[i]) << endl;
    }
}

int main(){
    int t;
    cin >> t;
    vector<string> phrases;
    for(int i = 0; i<t; i++){
        string a;
        getline(cin, a);
        phrases.push_back(a);
        max_phrase = max(a.size()+1, max_phrase);
    }
    permuted_index(phrases);
    return 0;
}
