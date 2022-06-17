#include<iostream>
#include<exception>
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

class Linked_list
{
    Node* Start = 0;
    public:
        void set_start(Node &N){
            Start = &N;
        }
        void input_list(Node*,int);
        void traverse(void);
        int num_elements(void);
        void unsorted_search(int item);
        void sorted_search(int item);
        void insert(int ITEM,Node* LOC);
        // Insertion is assumed to be into a sorted List
        Node* find(int ITEM); 
        void insert(int ITEM);
        friend Linked_list& Merge(Linked_list L1, Linked_list L2);
        void remove(Node* LOC,Node* LOCP);
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

void Linked_list::traverse(void)
{
    // Set a pointer to the start
    Node* Nptr = this->Start;
    cout << "List : " ;
    // Print till the pointer to link element is 0
    while ((*Nptr).link() != 0)
    {
        cout << (*Nptr).info() << "," ;
        // Setting pointer to the link Node
        Nptr = (*Nptr).link();
    }
    cout << "\n";
}

void Linked_list::insert(int ITEM,Node* LOC)
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
            NEW->set_link(0);
        }
        NEW->set_Data(ITEM);
        // If LOC = 0, insert element at the start  
        if (LOC == 0){
            NEW->set_link(Start) ;
            Start = NEW ;
        }
        else 
        {
            // Set the link of NEW as the link of link
            NEW->set_link(LOC->link()) ;
            LOC->set_link(NEW);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Node* Linked_list::find(int ITEM){
    /*
    Here we assume that the given Linked List is sorted
    This function would return the pointer to the location ITEM in 
    a sorted Linked List
    */

    // In case of Empty Linked List
    if (Start == 0){
        return 0;
    }
    if (ITEM < Start->info()){
        return 0;
    }
    // Save Stores the previous Node
    // PTR Stores the current Node
    Node* SAVE = Start;
    Node* PTR = Start->link();
    while (PTR->link() != 0){
        if (ITEM < PTR->info()){
            return SAVE ;
        }
        else{
            SAVE = PTR ;
            PTR = PTR->link();
        }
    }
    return SAVE ;
}

void Linked_list::insert(int ITEM){
    // Insertion is assumed to be into a sorted List 
    Node* LOC = this->find(ITEM);
    this->insert(ITEM,LOC);
}

Linked_list& Merge(Linked_list L1, Linked_list L2)
{
    Linked_list L_ret;
    Node* ptr1 = L1.Start;
    Node* ptr2 = L2.Start;
    Node *ptr3,*Save;
    // Ptr3 points to the first Node
    ptr3 = new Node;
    // Initialising the next node of the overall
    // Sorted List and Storing its pointer in Save
    Node* NextNode = new Node;
    Save = NextNode;
    // Set ptr3 as the start
    L_ret.set_start(*ptr3);
    // To append to the larger sorted list
    // till one of them gets exhausted
    while(ptr1!=0 && ptr2!=0){
        if (ptr1->info() > ptr2->info()){
            ptr3->set_link(Save);
            ptr3->set_Data(ptr2->info());
            ptr2->set_link(ptr2->link());
        }
        else{
            ptr3->set_link(Save);
            ptr3->set_Data(ptr1->info());
            ptr1->set_link(ptr1->link());
        }
        Node* NextNode = new Node;
        Save = NextNode;
    }
}

int main()
{
    int num;
    cout << "Enter the number of elements in the list : ";
    cin >> num;
    Linked_list L1;
    
    // Creating a starting node and setting it as start
    Node *Nptr = new Node;
    L1.set_start(*Nptr);
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

    // Setting the pointer of last element as 0
    (*Nptr).set_link(0);
    L1.traverse();
    
    //Inserting an an element
    cout << "Enter an Element to insert : " ;cin >> el;
    L1.insert(el);
    L1.traverse();


    return 0;
}