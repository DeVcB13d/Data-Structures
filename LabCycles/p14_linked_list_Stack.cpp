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

class Stack
{
        Node* TOP;
    public:
        void set_TOP(Node *N){
            TOP = N;
        }
        void input_stack(Node*,int); 
        void PUSH(int ITEM);
        int POP();
        friend void print(Stack &S);
};

void print(Stack &S)
{
    Node* CURR = S.TOP;
    cout << "[ ";
    while(CURR->link() != 0)
    {
        cout << CURR->info() << " ";
        CURR = CURR->link();
    }
    cout << " ]\n";
}

void Stack::input_stack(Node* Nptr,int num){
    this->set_TOP(Nptr);
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
    Nptr->set_link(0);
}

void Stack::PUSH(int ITEM)
{
    try
    {
        // Insertion into Start
        Node* NEW = new Node;
        if (NEW==NULL)
        {
            throw "OVERFLOW";
        }
        NEW->set_Data(ITEM);
        NEW->set_link(TOP);
        TOP = NEW;
    }
    catch(const char* &c)
    {
        cout << c << '\n';
    }
}

int Stack::POP()
{
    try
    {
        if (TOP->link() == 0)
        {
            throw "UNDERFLOW ERROR";
        }
        int ITEM = TOP->info();
        Node* temp = TOP;
        TOP = TOP->link();
        delete temp;
        return ITEM;
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    
}

// Implementation
int main()
{
    int Nels;
    cout << "Number of elements : ";
    cin >> Nels; 
    Stack stk ;
    Node* Top1 = new Node;
    stk.input_stack(Top1,Nels); 
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
            stk.PUSH(el);
        }
        else if(choice==2){
            int ITEM = stk.POP();
            std::cout << ITEM << " removed\n";
        }
        else if(choice==3)
        {
            std::cout<<"Exiting...\n";
        }
        std::cout << "Output : "; 
        print(stk);
    }
    return 0;
}