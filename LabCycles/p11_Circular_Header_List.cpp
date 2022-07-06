#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* ptr;
    public:
        void set_Data(int d){
            data = d;
        }
        void set_link(Node* N){
            ptr = N;
        }
        int info(){
            return data;
        }
        Node* link(){
            return ptr;
        }
};
class Header
{
    public:
        int size;
        void* Next;
};

class Linked_list
{
    Node* Start = 0;
    public:
        void set_start(Node &N){
            Start = &N;
        }
        void input_list(Node*,int);
        void traverse(void);
        void insert(int el);
        void Delete(int el); 
};

void Linked_list::input_list(Node* Nptr,int num){
    // Inputting the Linked List
    cout << "Enter N elements : " ;
    int el;
    for(int i = 0 ; i < num ; i++){
        cin >> el ;
        // Dynamically allocating a new Node
        Node* new_Node = new Node; 
        // Setting the Data and Pointer to new_node
        // to its previous node
        (*Nptr).set_Data(el);
        (*Nptr).set_link(new_Node);
        // Setting the Node pointer to new_Node
        Nptr = new_Node;
    }
}