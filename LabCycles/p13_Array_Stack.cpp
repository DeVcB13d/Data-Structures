#include<iostream>
#include<exception>


class Stack
{
    // Array to store DATA
    int* DATA;
    int TOP;
    // Maximum space of the array
    int MAXD;
    public:
        Stack(int* Arr,int Nels,int M = 100){
            DATA = new int[M];
            // MAXD points to the last element
            MAXD = M;
            for(int i = 0 ; i < Nels ; i++){
                DATA[i] = Arr[i]; 
            }
            // TOP points to the last element
            // Nels - 1 since index starts from 0
            TOP = Nels-1;
        }
        void PUSH(int ITEM);
        int POP();
        friend void print(Stack &S);
};

void print(Stack &S)
{
    std::cout << "[ ";
    for(int p = 0 ; p <= S.TOP ; p++)
    {
        std::cout << S.DATA[p] << " ";
    }
    std::cout << " ]\n";
}

void Stack::PUSH(int ITEM)
{
    
    try
    {
        if (TOP == MAXD-1)
        {
            throw "DATA OVERFLOW\n";
        }
        TOP++;
        DATA[TOP] = ITEM;
    }
    catch(const char* exc)
    {
        std::cout << exc << '\n';
    }
}

int Stack::POP()
{
    try
    {
        if (TOP == -1)
        {
            throw "DATA UNDERFLOW";
        }
        int ITEM = DATA[TOP];
        DATA[TOP] = NULL;
        TOP--;
        return ITEM;
    }
    catch(const char* exc)
    {
        std::cout << exc << '\n';
    }
    return NULL;
}


// Implementation
int main()
{
    int Nels;
    int* Sin;
    std::cout << "Number of elements : ";
    std::cin >> Nels; 
    Sin = new int [Nels];
    std::cout << "Input datas : ";
    for(int k = 0 ; k < Nels;k++)
    {
        std::cin>>Sin[k];
    }
    Stack stk(Sin,Nels,20);
    print(stk);
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