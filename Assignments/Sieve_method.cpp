#include<iostream>
using namespace std;

void SievePrime(int N)
{
    int* NUM = new int [N + 1];
    bool* isMarked = new bool[N+1];
    for(int i = 0 ; i < N+2 ; i++)
    {
        //initialisind the values for 2 arrays
        //Num to store integers from 0 to N
        NUM[i] = i;
        //to check for marking, default = 0
        isMarked[i] = 0;
    }
    int k = 2;
    while (k*k <= N)
    {
        for(int j = k*k ; j < N ; j++)
        {
            if (isMarked[j] != 1){
                if (NUM[j]%k == 0){
                    isMarked[j] = 1 ;
                }
            }
        }
        //increase k to the next unmarked index
        do{
            k++;
        }while (isMarked[k] == 1);
    }
    //to print the unmarked elements
    for(int i = 2 ; i < N ; i++)
    {
        if (isMarked[i] == 0){
            cout << i << " " ;
        }
    }
    cout << "\n";
}

int main()
{
    int lim;
    cout << "Enter the limit : ";
    cin >> lim ;
    SievePrime(lim);
    return 0;
}