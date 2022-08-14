#include<iostream>
using namespace std;

class Node 
{
    public: 
        int DATA;
        Node* link;
};

class LinkedList_queue
{
        Node* FRONT = 0;
        Node* REAR = 0;
    public:
        void llq_insert(int item);
        int llq_delete(void);
        friend void print(LinkedList_queue &L);
};

void print(LinkedList_queue &L)
{
    Node* PTR = L.FRONT;
    while(PTR->link != 0)
    {
        cout << PTR->DATA << " ";
        PTR = PTR -> link ;
    }
}

void LinkedList_queue::llq_insert(int item)
{
    try
    {
        Node* NEW = new Node ;
        if (NEW == NULL)
        {
            throw "MEMORY NOT ALLOCATED";
        }
        NEW->DATA = item;
        if (FRONT == 0)
        {
            FRONT = NEW;
            NEW->link = 0;
            REAR = NEW;
        }
        else
        {
            REAR->link = NEW;
            NEW->link = 0;
        }
    }
    catch(const char* &e)
    {
        std::cout << e << '\n';
    }
}    

int LinkedList_queue::llq_delete()
{
    try
    {
        if(FRONT == 0)
        {
            throw "UNDERFLOW";
        }
    }
    catch(const char* &e)
    {
        std::cout << e << '\n';
    }
}