//Program to insert and delete an element from an array
#include<iostream>
#include "Linear_Array.h"
using namespace std;

class Array 
{
    int* DATA;
    int N;
    int MAXN;
    public:
        Array(int n,int maxn = 100)
        {
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
