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
        void insert(int ITEM,Node* LOC);
        Node* find(int ITEM);
        void remove(int ITEM);
        void traverse(void);
};

void double_Linked_List::traverse(void)
{
    // Set a pointer to the start
    Node* Nptr = this->Start;
    // Print till the pointer to link element is 0
    while ((Nptr->FORW!= 0)
    {
        cout << Nptr->DATA << "," ;
        // Setting pointer to the link Node
        Nptr = Nptr->DATA;
    }
    cout << "\n";
}

void double_Linked_List::insert(int ITEM,Node* LOC)
{
    /*
    To insert ITEM after LOC such that LOC would point to
    the node with ITEM
    */
    try{
        Node *NEW = new Node;
        // Throw an exception when memory is not allocated
        if (NEW==NULL)
        {
            throw std::bad_alloc();
        }
        // For an empty Linked List
        if (Start == 0){
            Start = NEW;
            NEW->FORW = 0;
            NEW->BACK = Start;
        }
        NEW->DATA = ITEM;
        // If LOC = 0, insert element at the start  
        if (LOC == 0){
            NEW->FORW = 0 ;
            NEW->BACK = Start;
        }
        else 
        {
            // Set the link of NEW as the link of link
            NEW->FORW = LOC->FORW;
            NEW->BACK = LOC;
            LOC->FORW = NEW;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Node* double_Linked_List::find(int ITEM){
    /*
    Here we assume that the given Linked List is sorted
    This function would return the pointer to the location ITEM in 
    a sorted Linked List
    */

    // In case of Empty Linked List
    if (Start == 0){
        return 0;
    }
    if (ITEM < Start -> DATA){
        return 0;
    }
    // Save Stores the previous Node
    // PTR Stores the current Node
    Node* SAVE = Start;
    Node* PTR = Start-> FORW;
    while (PTR->FORW != 0){
        if (ITEM < PTR->DATA){
            return SAVE ;
        }
        else{
            SAVE = PTR ;
            PTR = PTR->FORW;
        }
    }
    return SAVE ;
}

void Linked_list::insert(int ITEM){
    // Insertion is assumed to be into a sorted List 
    Node* LOC = this->find(ITEM);
    this->insert(ITEM,LOC);
}

int Linked_list::remove(Node* LOC,Node* LOCP)
{
    // To find the location LOC of item and the
    // Location of the ITEM before LOCP
    if (Start == 0)
    {
        return 0;
    }
    if (LOCP == 0)
    {
        Start = Start->link();
        LOC->set_link(0);
        int d = LOC->info();
        delete LOC;
        return d;
    }
    else
    {
        LOCP->set_link(LOC->link());
        int ret = LOC->info();
        LOC->set_link(0);
        delete LOC;
        return ret;
    }
}

void Linked_list::find_del(int ITEM,Node* &LOC,Node* &LOCP)
{
    // In the case of an empty Linked List
    if (Start == 0)
    {
        LOC = 0;
        LOCP = 0;
        return;
    }
    // When ITEM is at the start
    if (Start->info() == ITEM)
    {
        LOCP = 0;
        LOC = Start;
        return;
    }
    else
    {
        Node* SAVE = Start;
        Node* PTR = Start->link();
        while(PTR->link() != 0)
        {
            if (PTR->info()==ITEM)
            {
                LOC = PTR;
                LOCP = SAVE;
                return;
            }
            else
            {
                SAVE = PTR;
                PTR = PTR->link();
            }
        }
    }
    LOC = 0;
    LOCP = 0;
    return;
}

void Linked_list::remove(int ITEM)
{
    Node* LOC1;
    Node* LOCP1;
    this->find_del(ITEM,LOC1,LOCP1);
    if (LOC1 == 0)
    {
        cout << "Element does not exist\n";
    }
    else
    {
        this->remove(LOC1,LOCP1);
        cout << "Deleted Successfully\n";
    }
}