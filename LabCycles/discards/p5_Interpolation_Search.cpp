#include <iostream>
using namespace std;

int interpolation_search(int *DATA,int ITEM,int UB,int LB = 0)
{
    int BEG = LB ;
    int END = UB ;
    int POS;
    while (BEG <= END && (ITEM >= DATA[BEG] && ITEM <= DATA[END]))
    {
        POS = BEG + (ITEM - DATA[BEG])/(DATA[BEG] - DATA[END])*(END - BEG);
        if (DATA[POS] == ITEM)
        {
            return POS;
            break;
        }
        else if (DATA[POS] > ITEM)
        {
            END = POS - 1 ;
            break;
        }
        else
        {
            BEG = POS + 1 ;
        }
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
    for(int i = 0 ; i < n ; i++){
        cin >> Arr[i];
    }
    int exit = 1;
    while(exit != 0)
    {
        cout << "Enter an element to search : ";
        int search_elem;
        cin >> search_elem;
        int ret_index = interpolation_search(Arr,search_elem,n);
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