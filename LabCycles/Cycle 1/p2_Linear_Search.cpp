#include <iostream>
#include "Linear_Array.h"
using namespace std;

int Linear_Search(Linear_Array &A,int ITEM)
{
    int LOC = -1;
    for(int i=0;i<A.N;i++)
    {
        if (A.DATA[i]==ITEM)
        {
            LOC = i;
        }
    }
    if (LOC>=0)
    {
        return LOC;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int size;
    int Arr[100];
    cout << "Enter the array size : ";cin >> size;
    cout << "Enter the elements : ";
    for(int i = 0; i <size; i++)
    {
        cin >> Arr[i] ;
    }
    Linear_Array A1(Arr,size);
    A1.display();
    int exit = 1;
    while(exit != 0)
    {
        int Search_elem;
        cout << "Enter the element to search : ";
        cin >> Search_elem;
        //cout << "Hiu\n";
        int ret_index = Linear_Search(A1,Search_elem);
        if (ret_index== -1)
        {
            cout << "Element not found\n" ;
        }
        else 
        {
            cout << "Element " << Search_elem << " found at " << ret_index << endl;
        }
        cout << "Enter 0 to exit : ";
        cin >> exit;
    }
}
