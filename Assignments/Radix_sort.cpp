#include<iostream>
#include<cmath>
using namespace std ;
void display(int* DATA,int N)
{
    cout << "{";
    for (int i = 0 ; i < N ; i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}


int maxdigits(int* arr,int len)
{
    int max = arr[0] ; 
    for(int i = 0 ; i < len ; i++)
    {
        if (max<arr[i]){
            max = arr[i] ;
        }
    }
    int maxdigits = 0;
    while(max > 0)
    {
        max = max / 10 ;
        maxdigits++ ;
    }
    return maxdigits ;
}


void copy(int *arr1,int *arr2,int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        arr2[i] = arr1[i];
    }
}

void radix_sort(int* arr,int len)
{
    int M  = maxdigits(arr,len) ;
    for(int p = 0 ; p < M ; p++)
    {
        int *tarr = new int[len];
        int tptr = 0;
        for(int d = 0 ; d < 10 ; d++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                int el = arr[j];
                int pr = pow(10,p);
                int sd = (el/pr)%10;
                if (sd == d)
                {
                    cout << sd << "," << d << "\n" ;
                    tarr[tptr] = el ;
                    display(tarr,tptr);
                    tptr++;
                }
            }
            cout << "\n";
        }
        copy(arr,tarr,len);
        
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
    radix_sort(Arr,n-1);
    cout << "After sorting : ";
    display(Arr,n);
    return 0;
}