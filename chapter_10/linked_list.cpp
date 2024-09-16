// linked list implementation that provides bi-directional iterators and thus
// supports library algorithms like reverse.

#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class linked_list{
public:
    typedef size_t size_type;
private:
    struct Node{
        T val;
        Node* prev;
        Node* next;
    };
    Node header;
    Node tail;
    size_type _size = 0;
    void empty_init(){
        header.next = &tail;
        header.prev = nullptr;
        tail.prev = &header;
        tail.next = nullptr;
        header.val = 0;
        tail.val = 0;
    }
    template <class Iter>
    void create(Iter it, Iter end){
        for(;it!=end;it++){
            push_back(*it);
        }
    }
    void destroy();
public:
    struct Iterator{
    private:
        Node *nodeptr;
        bool reverse;
    public:
        using iterator_category = bidirectional_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        Iterator(Node* _nodeptr, bool _reverse) : nodeptr(_nodeptr), reverse(_reverse){}
        reference operator*() const {return nodeptr->val;}
        pointer operator->() {return &(nodeptr->val);}
        Iterator& operator--(){
            if(reverse){
                nodeptr = nodeptr->next;
            }
            else{
                nodeptr = nodeptr->prev;
            }
            return *this;
        }
        Iterator operator--(T){
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }
        Iterator& operator++(){
            if(reverse){
                nodeptr = nodeptr->prev;
            }
            else{
                nodeptr = nodeptr->next;
            }
            return *this;
        }
        Iterator operator++(T){
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator& a, const Iterator& b){
            return a.nodeptr==b.nodeptr;
        }
        friend bool operator!=(const Iterator& a, const Iterator& b){
            return a.nodeptr!=b.nodeptr;
        }
    };
    linked_list(){empty_init();}
    template <class Iter>
    linked_list(Iter it, Iter end){empty_init(); create(it, end);}
    linked_list(linked_list<T>& l2){
        empty_init(); 
        create(l2.begin(), l2.end());
    }
    linked_list<T>& operator=(linked_list<T>& l2){
        destroy();
        empty_init();
        create(l2.begin(), l2.end());
        return *this;
    }
    ~linked_list(){destroy();}
    size_t size(){return _size;}
    void push_back(T);
    void push_front(T);
    Iterator begin() {return Iterator(header.next, false);}
    Iterator end() {return Iterator(&tail, false);}
    Iterator rbegin() {return Iterator(tail.prev, true);}
    Iterator rend() {return Iterator(&header, true);}
};

template <class T>
void linked_list<T>::push_back(T t){
    linked_list<T>::Node *last = tail.prev;
    linked_list<T>::Node *newnode = new Node;
    newnode->val = t;
    newnode->prev = last;
    newnode->next = &tail;
    last->next = newnode;
    tail.prev = newnode;
    _size++;
}

template <class T>
void linked_list<T>::push_front(T t){
    linked_list<T>::Node *first = header.next;
    linked_list<T>::Node *newnode = new Node;
    newnode->val = t;
    newnode->prev = &header;
    newnode->next = first;
    first->prev = newnode;
    header.next = newnode;
    _size++;
}

template <class T>
void linked_list<T>::destroy(){
    Node *current = header.next;
    while(current!=&tail){
        Node *previous = current;
        current = current->next;
        delete previous;
    }
}

template <class T>
void printList(linked_list<T>& l){
    for(auto it=l.begin();it!=l.end();++it){
        cout << *it << " ";
    }
    cout << endl;
}

template <class Iter>
void printIter(Iter it, Iter e){
    for(; it!=e; it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    linked_list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    printIter(l.begin(), l.end());

    reverse(l.begin(), l.end());
    printIter(l.begin(), l.end());

    l.push_front(5);
    printIter(l.begin(), l.end());

    reverse(l.begin(), l.end());
    printIter(l.begin(), l.end());

    replace(l.begin(), l.end(), 3, 9);
    printIter(l.begin(), l.end());
    cout << l.size() << endl;

    linked_list<int> l2 = l;
    printIter(l2.begin(), l2.end());

    l2.push_back(6);
    printIter(l.begin(), l.end());
    printIter(l2.begin(), l2.end());

    l = l2;
    printIter(l.begin(), l.end());
    printIter(l2.begin(), l2.end());

    //linked_list<int> l2 = l;
    //printIter(l.begin(), l.end());
    return 0;
}