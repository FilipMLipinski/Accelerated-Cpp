/*
cache = new MyCache(size=3)

cache.insert(a) // (a, 1)
cache.lookup(a) // true, (a, 2)
cache.insert(b) // (a, 2), (b, 1)
cache.insert(c) // (a, 2), (b, 1), (c, 1)
cache.insert(d) // (a, 2), (b, 1), (d, 1)

bool lookup(char c)
void insert(char c)
*/
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;


class MyCache{
    set<pair<int, char>> s;
    unordered_map<char , int> m;
    int max_size;
    int size;
    public:
    void printMap(){
        for(auto it = m.begin();it!=m.end();it++){
            cout << it->first << " " << it->second<<endl;
        }
    }
    MyCache(int max_s){max_size = max_s; size = 0;}
    bool lookup(char c){
        if(m.count(c)){
            pair<int, char> replacing = {m[c], c};
            s.erase(replacing);
            pair<int, char> newpair = {m[c]+1, c};
            s.insert(newpair);
            m[c]++;
            return true;
        }
        return false;
    }
    void insert(char c){
        if(!lookup(c)){
            if(size==max_size){
                char removed = s.begin()->second;
                s.erase(s.begin());
                m.erase(removed);
                size--;
            }
            pair<int, char> newpair = {1, c};
            s.insert(newpair);
            m[c] = 1;
            size++;
        }
    }
};

int main(){
    MyCache cache = MyCache(3);
    cache.insert('a'); // (a, 1)
    cout << cache.lookup('a') << endl; // true, (a, 2)
    cache.insert('b'); // (a, 2), (b, 1)
    cache.insert('c'); // (a, 2), (b, 1), (c, 1)
    cache.insert('d'); // (a, 2), (b, 1), (d, 1)
    cout << cache.lookup('a') << endl;
    cout << cache.lookup('b') << endl;
    cout << cache.lookup('c') << endl;
    cout << cache.lookup('d') << endl;
    return 0;
}