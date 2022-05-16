//Program to insert and delete an element from an array
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
            for(int j = 0;j<N;j++)
            {
                DATA[j] = D[j];
            }
        }
        void display()
        {
            cout << "{";
            for(int i =0;i<N;i++)
            {
                cout << DATA[i] << ",";
            }
            cout << "}\n";
        }
        void Insert(int K,int ITEM)
        {
            int j = N;
            while(j>=K)
            {
                DATA[j+1] = DATA[j];
                j--;
            }
            DATA[K] = ITEM;
            N=N+1;
        }
            
        int Delete(int K)
        {
            int ITEM = DATA[K];
            for(int i=K+1;i<N;i++)
            {
                DATA[i-1] = DATA[i];
            }
            N = N-1;
            return ITEM;
        }
};

int main()
{
    int A1[8] = {1,3,4,6,6,7,4,3};
    Array Ar1(A1,8);
    Ar1.display();
    Ar1.Insert(5,12);
    Ar1.display();
    int D1 = Ar1.Delete(2);
    cout << "D1 = " << D1 << "\n";
    Ar1.display();
} 
