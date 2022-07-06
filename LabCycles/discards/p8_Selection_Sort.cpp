#include <iostream>
#include "Linear_Array.h"

void selection_sort(int* DATA,int UB,int LB = 0)
{
    for(int i = 0 ; i < UB ; i++)
    {
        for (int j = i + 1 ; j < UB ; j++)
        {
            if (DATA[i] > DATA[j]) 
            {
                int temp = DATA[j];
                DATA[j] = DATA[i];
                DATA[i] = temp;
            }
        }
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
    int exit = 1;
    cout << "Before Sorting : ";
    display(Arr,n);
    selection_sort(Arr,n-1);
    cout << "After sorting : ";
    display(Arr,n);
    return 0;
}