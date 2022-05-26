#include <iostream>
using namespace std;

class Linear_Array
{
    public:
        int* DATA;
        int N;
        Linear_Array()
        {
            DATA = new int[0];
            N = 0;
        }
        Linear_Array(int *D,int n)
        {
            DATA = new int[n];
            N = n;
            for(int j = 0;j<N;j++)
            {
                DATA[j] = D[j];
            }
        }
        Linear_Array(Linear_Array &A)
        {
            A.N = N;
            for(int i = 0;i<N;i++)
            {
                A.DATA[i] = DATA[i]; 
            }
        }
        friend ostream &operator<<(ostream &output,Linear_Array A);
        void display();
};

void Linear_Array::display()
{
    cout << "{";
    for(int i = 0;i<N;i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

ostream &operator<<(ostream &output,Linear_Array A)
{
    cout << "N  = " << A.N << endl;
    cout << "{";
    for(int i = 0;i<A.N;i++)
    {
        cout << A.DATA[i] << ",";
    }
    cout << "}\n";
    return output;
}
void input_array(int &size,int* arr,int* elems)
{
    cout << "Enter " << size << " elements : " ;
    arr = new int [size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}