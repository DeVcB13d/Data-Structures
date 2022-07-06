#include <iostream>
#include "Linear_Array.h"

void insertion_sort(int* DATA,int UB,int LB = 0)
{
    int ptr;
    for(int i = LB + 1 ; i < UB ; i++ )
    {
        int ptr = i - 1;
        int temp = DATA[i];
        while (ptr >= 0 && temp < DATA[ptr]) 
        {
            DATA[ptr+1] = DATA[ptr] ;
            ptr-- ;
        }
        DATA[ptr+1] = temp ;
    }
}

int main()
{
    int Arr[100];
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    cout << "Enter the array elements :";
    for(int i = 0 ; i < n ; i++){
        cin >> Arr[i];
    }
    cout << "Before Sorting : ";
    display(Arr,n);
    insertion_sort(Arr,n);
    cout << "After sorting : ";
    display(Arr,n);
    return 0;
}
