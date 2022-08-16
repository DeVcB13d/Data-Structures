#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        void* ptr;
};

class Header
{
    public:
        int size;
        Node* Next;
};

class Linked_list
{
    Header* Start;
    public:
        void input_list(Node*,int);
        void traverse(void);
        void insert(int el);
        void Delete(int el); 
};

void Linked_list::insert(int el)
{
    if ()
}

void Linked_list::input_list(Node* Nptr,int num)
{
    int elem ;
    cout << "Enter " << num << " elements : \n";
    for(int i = 0 ; i < num ; i++ ){
        cin >> elem ;
        this->insert(elem);
    }
}
