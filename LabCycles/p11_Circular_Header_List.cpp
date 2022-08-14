#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* ptr;
};

class Header
{
    public:
        int size;
        Node* Next;
};

class Linked_list
{
    void* Start;
    public:
        void input_list(Node*,int);
        void traverse(void);
        void insert(int el);
        void Delete(int el); 
};

void Linked_list::input_list(Node* Nptr,int num)
{
    
}