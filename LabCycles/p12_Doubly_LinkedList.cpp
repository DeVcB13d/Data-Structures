#include<iostream>
using namespace std;

class Node
{
    public:
        int DATA ;
        // Pointer to forwardd node
        Node* FORW;
        // Pointer to backward node
        Node* BACK;
};

class double_Linked_List
{
    Node* Start = NULL;
    public:
        void search(int ITEM);
        void insert(int ITEM);
        void remove(int ITEM);
};

void double_Linked_List::insert(int ITEM)
{
    // Assuming to insert into a sorted linked list(ascending)
    Node* ptr = Start;
    while(ptr != 0 or ptr->DATA < ITEM)
    {
        ptr = ptr->FORW;
    }
    try
    {
        Node* NEW = new Node;
        if(NEW == NULL){
            throw "MEMORY NOT ALLOCATED\n";
        }
        NEW->DATA = ITEM ;
        if (Start == NULL)
        {
            Start = NEW;
            Start->BACK = NEW;
            Start->FORW = Start;
        }
    }
    catch(const char*& e)
    {
        cout << e << '\n';
    }
    

}