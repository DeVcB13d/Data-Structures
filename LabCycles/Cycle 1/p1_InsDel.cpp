//Program to insert and delete an element from an array
#include<iostream>
#include "Linear_Array.h"
using namespace std;

class Array : public Linear_Array
{
    public:
        Array():Linear_Array(){}
        Array(int *D,int n):Linear_Array(D,n)
        {
            
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

void Array::Insert(int K,int ITEM)
{
    //check if insertion is out of array bounds
    if (K<=N){ 
        //Store the current array in a temporary array
        Array A2 = Array(DATA,N);
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

int Array::Delete(int K)
{
    //Store the current array in a temporary array
    if (K < N)
    {
        Array A2 = Array(DATA,N);
        int ITEM = DATA[K];
        for(int i=K+1;i<N;i++)
        {
            DATA[i-1] = DATA[i];
        }
        N = N-1;
        return ITEM;
    }
    else 
    {
        return 0;
        cout << "Out of index\n";
    }
}
int main()
{
    int size;
    int Arr[100];
    cout << "Enter the array size : ";cin >> size;
    cout << "Enter the elements : ";
    for(int i = 0; i < size ; i++)
    {
        cin >> Arr[i] ;
    }
    Array Ar2(Arr,size);
    cout << "Array Created : ";
    Ar2.display();
    int choice = 0;
    while(choice != 3)
    {
        cout << "MENU\n1. Insert\n2. Delete\n3. Exit\n";
        cout << "Choose an option : ";cin>>choice;
        if (choice == 1)
        {
            int index,element;
            cout << "Enter the index to insert : ";cin >> index;
            cout << "Enter the element to insert : ";cin >> element;
            Ar2.Insert(index,element);
            cout << "New Array : ";
            Ar2.display();
        }
        else if (choice == 2)
        {
            int index;
            cout << "Enter the index to remove : ";cin >> index;
            int del = Ar2.Delete(index);
            cout <<"New array : ";
            Ar2.display();
            cout << "Deleted element : " << del << endl ;
        }
        else if (choice == 3)
        {
            cout << "Exiting......\n";
        }
        else {cout << "Invalid option\n";}
    }
    return 0;
} 
