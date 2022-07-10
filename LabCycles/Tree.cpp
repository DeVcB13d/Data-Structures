#include<iostream>
using namespace std;

class Node
{
    public:
        int DATA = -99999;
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
        void search(int ITEM,Node* &LOCP,Node* &LOC);
        void insert(int ITEM);
        int inorder_pred(int,Node*);
        void remove(int ITEM);
        void print(Node*);
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
};

void Binary_tree::print(Node* S)
{
    if (S != 0)
    {
        print(S->LEFT);
        cout << S->DATA<<"    ";
        print(S->RIGHT);
    }
}

void Binary_tree::inorder(Node* N){
    if (N == 0){
        return;
    }
    this->inorder(N->LEFT);
    cout << N->DATA << "  ";
    this->inorder(N->RIGHT);
}

void Binary_tree :: preorder(Node* N){
    if (N==0){return;}
    cout << N->DATA << "    ";
    preorder(N->LEFT);
    preorder(N->RIGHT);
}

void Binary_tree::postorder(Node* N){
    if (N==0){return;}
    postorder(N->LEFT);
    postorder(N->RIGHT);
    cout << N->DATA << "   ";
}

int Binary_tree::inorder_pred(int ITEM,Node* CURR)
{
    Node* PRE = CURR;
    while(PRE != 0 && PRE->LEFT!=0){
        PRE = PRE -> LEFT;
    }
    return PRE->DATA;
}

void Binary_tree::search(int ITEM,Node* &LOCP,Node* &LOC)
{
    Node* PTR = Root;
    while (ITEM != PTR->DATA)
    {
        
        if (ITEM < PTR->DATA){
            if (PTR->LEFT==0){
                LOC = 0;
                return;
            }
            LOCP = PTR;
            PTR = PTR -> LEFT;
        }
        else if (ITEM > PTR->DATA){
            if(PTR->RIGHT==0){
                LOC = 0;
                return;
            }
            LOCP = PTR;
            
            PTR = PTR -> RIGHT;
        }
    }
    if(ITEM == PTR->DATA){
        LOC = PTR;
    }
}

void Binary_tree::insert(int ITEM)
{
    try
    {
        /* Creating a Node with ITEM to insert*/
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
                throw "ELEMENT EXISTS";
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
        // Search and return the parent node
        Node* LOCP ;
        Node* LOC ;
        this->search(ITEM,LOCP,LOC);
        if(LOC==0){
            throw "ELEMENT DOES NOT EXIST";
        }
        cout << "LOCP : " << LOCP->DATA << endl;
        cout << "LOC : " << LOC->DATA << endl;
        if (LOC == 0){
            throw "Element Not found";
            return;
        }

        // When the Node to be deleted is a leaf
        if (LOC->LEFT == 0 && LOC->RIGHT == 0){
            //cout << "H1 : " << (LOCP->RIGHT)->DATA << endl;
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
        else if (LOC->LEFT != 0 && LOC->RIGHT==0){
            Node* temp = LOC;
            LOC = LOC -> LEFT;
            //delete temp;
            return;
        }
        else if (LOC->RIGHT != 0 && LOC->LEFT ==0){
            Node* temp = LOC;
            LOC = LOC -> RIGHT;
            //delete temp;
            return;
        }
        else if(LOC->LEFT != 0 && LOC->RIGHT != 0){
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
    /*
    //T1.set_root(ROOT);
    cout << "MENU : \n";
    cout << "1. INSERT\n";
    cout << "2. DELETE\n";
    cout << "3. PRINT\n";
    int choice = 0;
    while(choice != 4){
        cout << "\nCHOOSE : ";
        cin >> choice;
        if (choice == 1){
            int el;
            cout << "\nElement to insert : ";
            cin >> el;
            T1.insert(el);
            T1.print(T1.Root);
        }
        else if(choice == 2){
            cout << "\nElement to delete : ";
            int el;
            cin>>el;
            T1.remove(el);
            cout << "\n";
            T1.print(T1.Root);
        }
        else if(choice == 3){
            T1.print(T1.Root);
        }
    } 
    */
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
    cout << "\ninorder : \n";
    T1.print(T1.Root);
    cout << "\npreorder : \n";
    T1.preorder(T1.Root);
    cout << "\npostorder : \n";
    T1.postorder(T1.Root);

    for(int i = 0 ; i < 2 ; i++)
    {
        cout << "\ndelete : ";
        int el;
        cin>>el;
        T1.remove(el);
        cout << "\n";
        cout << "\ninorder : \n";
        T1.print(T1.Root);
        cout << "\npreorder : \n";
        T1.preorder(T1.Root);
        cout << "\npostorder : \n";
        T1.postorder(T1.Root);
    }
    return 0;
}