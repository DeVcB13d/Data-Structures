#include<iostream>
using namespace std;

void display(int* DATA,int N)
{
    cout << "{";
    for (int i = 0 ; i < N ; i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

void Bubble_Sort(int* DATA,int UB,int LB = 0)
{
    //To control the passes (N - 1)
    for(int i = LB ; i < UB ; i ++ )
    {
        // Inner loop to traverse and exchange
        // for each pass
        for(int j = 0 ; j < UB - i ; j++)
        {
            if (DATA[j] > DATA[j+1])
            {
                int temp = DATA[j];
                DATA[j] = DATA[j+1];
                DATA[j+1] = temp;
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
    Bubble_Sort(Arr,n-1);
    cout << "After sorting : ";
    display(Arr,n);
    return 0;
}