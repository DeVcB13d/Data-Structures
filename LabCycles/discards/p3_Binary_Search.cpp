#include <iostream>
using namespace std;


//To perform binary search we assume that the list given is already sorted
int binary_search(int *DATA,int UB,int ITEM,int LB = 0)
{
    //set beg to lower bound
    int BEG = LB;
    //set end to Upper bound
    int END = UB;
    int MID = (BEG + END)/2;
    while(DATA[MID] != ITEM && BEG <= END)
    {
        if (DATA[MID]<ITEM)
        {
            BEG = MID + 1;
        }
        else 
        {
            END = MID - 1;
        }
        MID = (BEG + END)/2;
    }
    if (DATA[MID] == ITEM)
    {
        return MID;
    }
    else
    {
        return -1;
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
    while(exit != 0)
    {
        cout << "Enter an element to search : ";
        int search_elem;
        cin >> search_elem;
        int ret_index = binary_search(Arr,n,search_elem);
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