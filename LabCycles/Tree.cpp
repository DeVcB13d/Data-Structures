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
        Node* search(int ITEM,Node* LOCP);
        void insert(int ITEM);
        int inorder_pred(int,Node*);
        void remove(int ITEM);
        void print(Node*);
};

void Binary_tree::print(Node* S)
{
    if (S != 0)
    {
        print(S->LEFT);
        cout << S->DATA<<"    ";
        print(S->RIGHT);
    }
    return;
}

int Binary_tree::inorder_pred(int ITEM,Node* CURR)
{
    Node* PRE = CURR;
    while(PRE != 0 && PRE->LEFT!=0){
        PRE = PRE -> LEFT;
    }
    return PRE->DATA;
}

Node* Binary_tree::search(int ITEM,Node* LOCP)
{
    Node* PTR = Root;
    while (ITEM != PTR->DATA)
    {
        LOCP = PTR;
        if (ITEM < PTR->DATA){
            if (PTR->LEFT==0){
                return 0;
            }
            PTR = PTR -> LEFT;
        }
        else if (ITEM > PTR->DATA){
            if(PTR->RIGHT==0){
                return 0;
            }
            PTR = PTR -> RIGHT;
        }
    }
    return PTR;
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
        while (true)
        {
            if (ITEM < PTR->DATA){
                if (PTR->LEFT==0){
                    PTR->LEFT = NEW;
                    return;
                }
                PTR = PTR -> LEFT;
            }
            else if (ITEM > PTR->DATA){
                if(PTR->RIGHT==0){
                    PTR->RIGHT = NEW;
                    return;
                }
                PTR = PTR -> RIGHT;
            }
            else if(ITEM == PTR->DATA){
                //throw "ELEMENT EXISTS";
                return;
            }
        }
    }
    catch(const char* e)
    {
        cout << e << '\n';
    }
}

void Binary_tree::remove(int ITEM){
    try
    {
        // Search and return the paren
        Node* LOCP = 0;
        Node* LOC = this->search(ITEM,LOCP);
        if (LOC == 0){
            throw "Element Not found";
            return;
        }

        // When the Node to be deleted is a leaf
        if (LOC->LEFT == 0 && LOC->RIGHT == 0){
            if (ITEM == (LOCP->RIGHT)->DATA){
                LOCP->RIGHT = 0;
            }
            else{
                LOCP->LEFT = 0;
            }
            delete LOC;
            return;
        }
        // When the 
        else if (LOC->LEFT != 0){
            Node* temp = LOC;
            LOC = LOC -> LEFT;
            delete temp;
            return;
        }
        else if (LOC->RIGHT != 0){
            Node* temp = LOC;
            LOC = LOC -> RIGHT;
            delete temp;
            return;
        }
        else{
            int P = inorder_pred(ITEM,LOC);
            this->remove(P);
            LOC->DATA = P;
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
    T1.insert(7);
    T1.insert(10);
    T1.insert(-2);
    T1.insert(8);
    T1.insert(3);
    T1.insert(11);
    T1.insert(-4);
    T1.insert(4);
    T1.insert(9);
    T1.insert(12);
    T1.print(T1.Root);
    for(int i = 0 ; i < 3 ; i++)
    {
        cout << "\ndelete : ";
        int el;
        cin>>el;
        T1.remove(el);
        cout << "\n";
        //T1.print(T1.Root);
    }
    return 0;
}