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
            DATA = new int[N];
        }
        Array(Array &A);
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        void Insert(int,int);
        int Delete(int);
        void display();
};

// Copy constructor
Array::Array(Array &A){
    DATA = new int[A.N];
    for(int i = 0 ; i < A.N ; i++){
        DATA[i] = A.DATA[i] ;
    }
}

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
    // Delete an element in the given index
    if (N==0 || K < 0 || K > N){
        return NULL;
    }
    else
    {
        int ret = DATA[K];
        // Assign the Next array value
        for(int i = K;i<N;i++){
            DATA[i] = DATA[i+1];
        }
        N--;
        return ret;
    }
}

// Dynamically insert ITEM at position K
void Array::Insert(int K,int ITEM)
{
    //check if insertion is out of array bounds
    if (K<=N){ 
        //Store the current array in a temporary array A2
        Array A2(*this);
        N=N+1;
        //Creating an array with the new size 
        DATA = new int [N];
        for(int j = 0 ; j < K ; j++)
        {
            DATA[j] = A2.DATA[j];
        }
        //Inserting item at the Kth position
        DATA[K] = ITEM;
        int j = N;
        //inserting remaining elements at their successive positions
        while(j>=K)
        {
            DATA[j+1] = A2.DATA[j];
            j--;
        }
    }
    else
    {
        cout << "Out of index \n";
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
    cout << "MENU : \n1. Insert\n2. Delete\n3. New Array\n4. Display\n5. Exit\n";
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