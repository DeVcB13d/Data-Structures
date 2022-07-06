#include <iostream>
using namespace std;

// While performing ternary search
// we assume that the given array is sorted

int ternary_search(int* DATA,int UB,int ITEM,int LB = 0)
{
    int BEG = LB;
    int END = UB;
    int MID1,MID2;
    while (BEG<=END){
        MID1 = (END - BEG)/3 + BEG ;
        MID2 = ((2*(END - BEG))/3) + BEG ; 
        cout << "MID1 : " << MID1 << " MID2 : " << MID2 << endl;
        if (DATA[MID1] == ITEM){
            return MID1;
        }
        else if (DATA[MID2] == ITEM){
            return MID2;
        }
        else if (DATA[MID1] > ITEM){
            END = MID1 - 1 ;
        }
        else if (DATA[MID2] < ITEM){
            BEG = MID2 + 1 ;
        }
        else{
            BEG = MID1 + 1 ; 
            END = MID2 - 1 ; 
        } 
    }
    return -1;
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
        int ret_index = ternary_search(Arr,n,search_elem);
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