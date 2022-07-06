#include<iostream>
using namespace std;

class Node
{
    public:
        int DATA;
        Node* LEFT;
        Node* RIGHT;
};

class Binary_tree
{
        
    public:
        Node* Root = 0;
        void set_root(Node* R){
            Root = R;
        }
        Node* search(int ITEM);
        void insert(int ITEM);
        void remove(int ITEM);
        void print(Node*);
};

void Binary_tree::print(Node* S)
{
    if (S  != NULL)
    {
        print(S->LEFT);
        cout << S->DATA << "  ";
        print(S->RIGHT);
        //cout << "\n";
    }
}

void Binary_tree::insert(int ITEM)
{
    try
    {
        Node* NEW = new Node;
        // throw when memory not allocated
        if (NEW == NULL)
        {
            throw "MEMORY NOT ALLOCATED";
        }
        // Set the left and right pointers as 0
        NEW->LEFT = 0;
        NEW->RIGHT = 0;
        // Assign DATA to NODE
        NEW->DATA = ITEM;
        // If its an empty Binary_tree
        if (Root==0)
        {
            Root = NEW;
            return;
        }
        // To traverse the Binary_tree
        Node* PTR = Root;

        // Find the location of the node to insert into
        while(PTR->LEFT != 0 && PTR->RIGHT != 0)
        {
            if (ITEM < PTR->DATA){
                PTR = PTR -> LEFT;
            }
            else if(ITEM > PTR->DATA){
                PTR = PTR -> RIGHT;
            }
            else{
                throw "ELEMENT ALREADY EXISTS";
            }
        }

        // Insert NEW to the Binary_tree
        if (PTR->DATA > ITEM)
        {
            PTR->LEFT = NEW;
        }
        else{
            PTR->RIGHT = NEW;
        }
    }
    catch(const char* e)
    {
        cout << e << '\n';
    }
}


int main()
{
    //Node* ROOT = new Node;
    Binary_tree T1 ;
    //T1.set_root(ROOT);
    T1.insert(8);
    T1.insert(5);
    T1.insert(9);
    T1.insert(17);
    T1.insert(13);
    T1.insert(3);
    T1.insert(7);
    //T1.insert(5);
    T1.insert(2);
    //T1.insert(-1);
    T1.print(T1.Root);
    return 0;
}