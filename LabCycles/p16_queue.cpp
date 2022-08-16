#include<iostream>
using namespace std;


// Circular queue

template <class T>
class QUEUE
{
        T* DATA;
        int N;
        int FRONT;
        int REAR;
    public:
        QUEUE(int MAX)
        {
            // Constructor to dynamically allocate 
            // MAX locations for the QUEUE
            N = MAX ;
            DATA = new T[MAX];
            FRONT = NULL;
            REAR = NULL;
        }
        void insert(T DATA);
        T remove();
        void print();
};

template <class T>
void QUEUE<T>::print()
{
    if (FRONT == NULL)
    {
        cout << "EMPTY\n" ;
        return;
    }
    for (int i = FRONT ; i < REAR + 1 ; i++ )
    {
        std::cout << DATA[i] << " ";
    }
    std::cout << "\n";
}

// To insert into circular QUEUE
template <class T>
void QUEUE<T>::insert(T ITEM)
{
    try
    {
        // IN the 2 cases of list being emptuy
        if( (FRONT == 1 and REAR == N) or (FRONT == REAR + 1))
        {
            throw "OVERFLOW ERROR" ; 
        }
        // Empty queue
        else if (FRONT==NULL)
        {
            FRONT = 1;
            REAR = 1;
        }
        // when REAR is at the end
        else if (REAR == N)
        {
            REAR = 1 ;
        }
        else
        {
            REAR = REAR + 1;
        }
        DATA[REAR] = ITEM;
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
}

template <class T>
T QUEUE<T>::remove()
{
    try
    {
        if (FRONT == NULL)
        {
            throw "UNDERFLOW ERROR";
            //return;
        }
        T item = DATA[FRONT];
        if (FRONT == REAR)
        {
            FRONT = NULL;
            REAR = NULL ;
        }
        else if(FRONT == N)
        {
            FRONT = 1;
        }
        else
        {
            FRONT = FRONT + 1;
        }
        return item;
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    
}


// int main()
// {
//     int len;
//     std::cout << "Enter length of queue : ";
//     std::cin >> len ;
//     QUEUE<int> Q(len);
//     std::cout << "Input : ";
//     int el;
//     for(int j = 0 ; j < len ; j++)
//     {
//         std::cin >> el;
//         Q.insert(el);
//     }
//     Q.print();
//     int e1 = Q.remove();
//     std::cout << "Deleted : " << e1 << std::endl ;
//     e1 = Q.remove();
//     std::cout << "Deleted : " << e1 << std::endl ;
//     e1 = Q.remove();
//     std::cout << "Deleted : " << e1 << std::endl ;
//     e1 = Q.remove();
//     std::cout << "Deleted : " << e1 << std::endl ;
//     Q.print();
// }
const int SIZE = 20;
int main()
{
    int Sin ;
    QUEUE<int> Q(SIZE);
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
            Q.insert(el);
        }
        else if(choice==2){
            int ITEM = Q.remove();
            std::cout << ITEM << " removed\n";
        }
        else if(choice==3)
        {
            std::cout<<"Exiting...\n";
        }
        std::cout << "Output : "; 
        Q.print();
    }
    return 0;
}