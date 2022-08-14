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
    public:
        Node* Start;
        void search(int ITEM);
        void insert(int ITEM);
        void remove(int ITEM);
};