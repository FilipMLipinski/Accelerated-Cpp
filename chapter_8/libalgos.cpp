#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class Iter>
void my_print(Iter a, Iter b){
    while(a!=b){
        cout << *a << " ";
        a++;
    }
    cout << endl;
}

template <class Iter, class Pred>
Iter my_partition(Iter a, Iter b, Pred p){
    // make a point to the first non-p elem;
    while(a!=b){
        if(!p(*a)) break;
        a++;
    }
    if(a==b) return a;
    Iter e = a;
    e++;
    while(e!=b){
        if(p(*e)){
            swap(*a++, *e);
        }
        e++;
    }
    return a;
}

template <class Iter, class T>
Iter my_remove(Iter a, Iter b, T t){
    Iter e = a;
    while(a!=b){
        if(*a!=t) *e++ = *a;
        a++;
    }
    return e;
}

template <class Iter, class UPred>
Iter my_find_if(Iter a, Iter b, UPred p){
    while(a!=b){
        if(p(*a)) return a;
        a++;
    }
    return a;
}

template <class Iter>
Iter my_search(Iter a, Iter b, Iter x, Iter y){
    while(a!=b){
        if(equal(x,y,a)) return a;
        a++;
    }
    return a;
}

template <class In, class T>
T my_accumulate(In a, In b, T t){
    while(a!=b){
        t+=*a++;
    }
    return t;
}

template <class In, class Out, class UFunc>
void my_transform(In a, In b, Out d, UFunc f){
    while(a!=b){
        *d++ = f(*a++);
    }
}

template <class In, class Out, class UPred>
void my_remove_copy_if(In a, In b, Out d, UPred p){
    while(a!=b){
        if(!p(*a)) *d++ = *a;
        a++;
    }
    return;
}

template <class In, class Out, class T>
void my_copy(In a, In b, Out d){
    while(a!=b){
        *d++ = *a++;
    }
    return;
}

template <class Iter, class T>
Iter my_find(Iter a, Iter b, T t){
    while(a!=b){
        if(*a==t) return a;
        a++;
    }
    return a;
}

template <class Iter>
bool my_equal(Iter b, Iter e, Iter d){
    while(b!=e){
        if(*b++!=*d++) return false;
    }
    return true;
}

int main(){
    vector<int> a = {0,4,5,9,0};
    vector<int> b = {4,5,9};
    //copy(a.begin(), a.end(), back_inserter(b));
    //my_remove_copy_if(a.begin(), a.end(), back_inserter(b), [](int i){return i<5;});
    //my_transform(a.begin(), a.end(), back_inserter(b), [](int n){return 2*n;});
    //my_print(b.begin(), b.end());
    //cout << my_accumulate(a.begin(), a.end(), 0);
    //auto i = my_find_if(a.begin(), a.end(), [](int a){return a>4;});
    //cout << (*i) << endl;
    //auto mid = my_partition(a.begin(), a.end(), [](int n){return n>=5;});
    //my_print(a.begin(), a.end());
    //cout << *mid << endl;
    return 0;
}