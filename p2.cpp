#include <iostream>
using namespace std;

int Linear_Search(int DATA[100],int N,int ITEM)
{
    int LOC = -1;
    for(int i=0;i<N;i++)
    {
        if (DATA[i]==ITEM)
        {
            LOC = i;
        }
    }
    if (LOC>=0)
    {
        return LOC;
    }
    else
    {
        cout << "Element not found";
        return -1;
    }
}

int main()
{
    int A1[8] = {1,3,4,6,6,7,4,3};
    int L1 = Linear_Search(A1,8,7);
    cout << "L1 = " << L1 <<endl;
    
}
