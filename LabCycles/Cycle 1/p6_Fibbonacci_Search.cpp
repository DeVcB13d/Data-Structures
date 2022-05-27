#include<iostream>
using namespace std;

int Fibbonacci_Search(int* DATA,int ITEM,int UB,int LB = 0)
{
    int F2 = 0 ;
    int F1 = 1 ;
    int Fb = 1 ;
    int offset = -1 ;
    //To get the 3 fibonacci less than UB
    while (Fb < UB)
    {
        F2 = F1 ;
        F1 = Fb ;
        Fb = F1 + F2 ;
    }
    while (Fb > 1)
    {
        int i = offset + F2;
        if (DATA[i] > ITEM)
        {
            F2 = F1 ;
            F1 = Fb ;
            Fb = F1 + F2 ;
            offset = i ;
        }
        else if (DATA[i] < ITEM)
        {
            Fb = F2 ;
            F1 = F1 - F2 ;
            F2 = Fb - F1 ;
        }
        else
        {
            return i ;
        }
    }
    if (F1 == 1 && DATA[offset + 1] == ITEM)
    {
        return offset + 1;
    }
    return -1 ;
}

int main()
{
    int Arr[100];
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    cout << "Enter the array elements :";
    for(int i = 1 ; i < n ; i++){
        cin >> Arr[i];
    }
    int exit = 1;
    while(exit != 0)
    {
        cout << "Enter an element to search : ";
        int search_elem;
        cin >> search_elem;
        int ret_index = Fibbonacci_Search(Arr,search_elem,n);
        if (ret_index != -1)
        {
            cout << "Element found at " << ret_index << "\n";
        }
        else 
        {
            cout << "Element not found\n";
        }
        cout << "Enter 0 to exit : ";
        cin >> exit ;
    }
}