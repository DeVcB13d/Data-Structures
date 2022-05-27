#include <iostream>
#include "Linear_Array.h"
using namespace std;

/*Subfunction to merge 2 sorted arrays with their given LB and UB*/
void Merge(int* A,int LBA,int EA,int* B,int LBB,int EB,int *C,int LBC)
{
    //Pointers to A,B and C arrays
    int NA = LBA;
    int NB = LBB;
    int UBA = LBA + EA + 1;
    int UBB = LBB + EB + 1;
    int NC = LBC;
    // Loop to merge till A or B exhausts
    while (NA <= UBA && NB <= UBB)
    {
        if (A[NA] > B[NB])
        {
            C[NC] = B[NB];
            NC++;
            NB++;
        }
        else 
        {
            C[NC] = A[NA];
            NC++;
            NA++;
        }
    }
    // To Add the remaining elements to C
    if (NA >= UBA)
    {
        for(int i = 0 ; i < EA - NB ; i++)
        {
            C[NC+i] = A[NA+i]; 
        }
    }
    else 
    {
        for(int i = 0 ; i < EB - NA; i++)
        {
            C[NC+i] = B[NB+i]; 
        }
    }
}

int main()
{
    int A1[6] = {3,5,6,10,40,90};
    int B1[5] = {2,7,8,9,100};
    int* C1 = new int [12];
    Merge(A1,0,6,B1,0,5,C1,0);
    display(C1,12);
}