#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> words;
    string w;
    vector<string>::size_type max_word = 0;
    while(cin >> w){
        if(w=="END") break;
        words.push_back(w);
        max_word = max(max_word, w.size());
    }
    sort(words.begin(), words.end());
    string current_word = "";
    int current_word_count;
    vector<string>::size_type count = words.size();
    // invariant: its the first word or we are not done counting the last one.
    for(int i = 0; i <count; ++i){
        if(current_word != words[i]){
            if(current_word!="") cout << current_word_count << endl;
            current_word_count = 1;
            current_word = words[i];
            cout << setw(max_word) << current_word << ": ";
        }
        else current_word_count++;
    }
    cout << current_word_count << endl;
}