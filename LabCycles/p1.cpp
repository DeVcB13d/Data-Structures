//To Insert and Delete an element from an array
#include<iostream>
using namespace std;

class Array
{
    int* DATA;
    int N;
    public:
        Array(int D[100],int n)
        {
            DATA = new int[n];
            N = n;
            for(int i=0;i<n;i++)
            {
                DATA[i] = D[i];
            }
        }
        int Arr_delete(int E);
        int Arr_insert(int N);
};

