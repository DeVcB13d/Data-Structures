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
    while(PTR != 0)
    {
        cout << PTR->DATA << " ";
        PTR = PTR -> link ;
    }
    cout << "\n";
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
            REAR = NEW ; 
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
        if(FRONT == REAR)
        {
            throw "UNDERFLOW";
        }
        Node* TEMP = FRONT ;
        int ITEM = FRONT->DATA ;
        FRONT = FRONT->link ;
        TEMP->link = 0 ;
        delete TEMP ;
        return ITEM ; 
    }
    catch(const char* &e)
    {
        cout << e << '\n';
    }
}

// Implementation
int main()
{
    LinkedList_queue LLQ ;
    std::cout << "MENU : \n1. PUSH\n2. POP\n3. EXIT\n";
    int choice = 0;
    while(choice != 3)
    {
        std::cout << "Select option : ";
        std::cin >> choice ;
        if (choice == 1){
            int el;
            std::cout << "Input element : ";
            std::cin>>el;
            LLQ.llq_insert(el);
        }
        else if(choice==2){
            int ITEM = LLQ.llq_delete();
            std::cout << ITEM << " removed\n";
        }
        else if(choice==3)
        {
            std::cout<<"Exiting...\n";
        }
        std::cout << "Output : "; 
        print(LLQ);
    }
    return 0;
}