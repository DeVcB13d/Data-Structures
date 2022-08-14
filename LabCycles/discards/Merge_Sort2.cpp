#include<iostream>
using namespace std;

void display(int* DATA,int N)
{
    cout << "{";
    for(int i = 0;i<N;i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

void Merge(int *A,int R,int LBA,int* B,int S,int LBB,int *C,int LBC)
{
    int NA=LBA,NB=LBB,PTR=LBC;
    int UBA=LBA+R-1,UBB=LBB+S-1;

    while(NA<=UBA && NB<=UBB)
    {
        if(A[NA]<B[NB])
        {
            C[PTR]=A[NA];
            NA=NA+1;
            PTR=PTR+1;
        }
        else
        {
            C[PTR]=B[NB];
            NB=NB+1;
            PTR=PTR+1;
        }
    }

    if(NA>UBA)
    {
        for(int i=0;i<=UBB-NB;i++)// may be upper bound
        {
            C[PTR+i]=B[NB+i];
        }
    }
    else
    {
        for(int i=0;i<=UBA-NA;i++)
        {
            C[PTR+i]=A[NA+i];
        }
    }
}

void MergePass(int* A,int N,int L,int* B){
    // L - elements in subarray
    // Q - Number of sub arrays
    int Q = N/(2*L) ;
    // S - Index of Elements that does not fit
    int S = 2*L*Q ;
    // R - Number of Balance elements
    int R = N - S ;
    int LB;
    for(int j = 1 ; j <= Q ; j++){
        LB = (2*j - 2)*L ; 
        Merge(A,L,LB,A,L,(LB+L),B,LB);
        // cout << "Under Merge Pass  : ";
        // B.display();
    }
    if (R <= L){
        for (int j = 0 ; j < R;j++){
            B[S+j] = A[S+j];
        }
    }
    else{
        Merge(A,L,S,A,R-L,L+S,B,S);
    }
    // A.display();
    // B.display();
}

void MergeSort(int* A,int* B,int N){
    int L = 1;
    // B.DATA = new int[N] ;
    // B.N = N ;
    while (L < N){
        MergePass(A,N,L,B);
        MergePass(B,N,2*L,A);
        L = 4 * L ;
    }
    
}

int main()
{
    int N;
    cout << "Enter number of elements : ";
    cin >> N ;
    int* Array = new int [N];
    int* temp = new int[N];
    cout << "Enter " << N << " elements : \n";
    for(int i = 0 ; i < N ; i++){
        cin >> Array[i] ;
    }
    MergeSort(Array,temp,N);
    display(Array,N);
}