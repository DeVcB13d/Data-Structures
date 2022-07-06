//Program to insert and delete an element from an array
#include<iostream>
using namespace std;

class Array 
{
    int* DATA;
    int N;
    int MAXN;
    public:
        Array(int n,int maxn = 100){
            N = n;
            DATA = new int[100];
            MAXN = 100;
        }
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        void Insert(int,int);
        int Delete(int);
        void display();
};

void Array::display()
{
    cout << "{";
    for(int i = 0;i<N;i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

int Array::Delete(int K)
{
    //
    if (N==0 || K < 0 || K > N){
        return NULL;
    }
    else
    {
        int ret = DATA[K];
        // Assign the Next array value
        for(int i = K;i++;i<N){
            DATA[i] = DATA[i+1];
        }
        N--;
    }
}

void Array::Insert(int ITEM,int K)
{
    // Insert DATA at position K
    try
    {
        // If array Space exceeds MAXN throw an exception
        if (N+1>=MAXN)
        {
            throw __throw_overflow_error;
        }
        // In the case of index being out of range
        if (K<0 || K>=N+1)
        {
            throw __throw_out_of_range;
        }
        for(int i = N ; i < K ; i--)
        {
            DATA[i+1] = DATA[i];
        }
        DATA[K] = ITEM ; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void get_array(int N,Array &A)
{
    cout << "Enter " << N << " elements : \n";
    int val ;
    for(int i = 0;i<N;i++)
    {
        cin >> val ;
        A.set_Data(i,val);
    }
}

int main()
{
    int len;
    cout << "Input the array length : " ; cin >> len;
    // Creating an array
    Array A1(len);
    // Getting the array input from user
    get_array(len,A1);
    // MENU
    int choice = 0;
    cout << "MENU : \n1. Insert\n2. Delete\n3. New Array\n4. Display\n5. Exit";
    while(choice < 5)
    {
        cout << "Choose an option : ";
        cin >>choice;
        if (choice==1)
        {
            int el;
            int pos;
            cout << "Enter the element to insert : " ; cin >> el;
            cout << "Enter the position to insert into : ";cin >> pos;
            A1.Insert(el,pos);
            cout << "New array:  \n";
            A1.display();
        }
        else if (choice==2)
        {
            int index;
            cout << "Enter the index to delete : "; cin >> index;
            int el = A1.Delete(index);
            cout << el << " Deleted \n";
            A1.display();
        }
        else if (choice==3)
        {
        int len;
        cout << "Input the array length : " ; cin >> len;
        Array A1(len);
        get_array(len,A1);
        }
        else if (choice==4)
        {
            A1.display();
        }
        else
        {
            cout << "EXiting \n";
        }
    }
}  