# include <iostream>
using namespace std;

void MERGING(float *A,int R,int LBA,float* B,int S,int LBB,float *C,int LBC)
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

void MERGE_PASS(float *A,int N,int L,float *B)
{
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int LB;

     for(int j= 1;j<=Q;j++)// may be j==0
    {
        LB=(2*j-2)*L;
        MERGING(A,L,LB,A,L,LB+L,B,LB);
    }

    if(R<=L)
    {
        for(int k=0;k<R;k++)
        {
            B[S+k]=A[S+k];
        }
    }
    else
    {
        MERGING(A,L,S,A,R-L,L+S,B,S);
    }
}

void MERGE_SORT(float *A,float *B,int N)
{
    int L=1;
    
    while(L<N)
    {
        MERGE_PASS(A,N,L,B);
        MERGE_PASS(B,N,2*L,A);
        L=4*L;
    }

}

int main()
{
    //float C[11]={6,8,2,3,16,5,1,33,24,55,23};
    float A[14]={66,33,40,22,55,88,60,11,80,20,50,44,77,30};
    float B[14];
    int n=14,l=1;

    MERGE_SORT(A,B,n);
    

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<", ";
    }
//     cout<<" "<<endl;

//      for(int i=0;i<n;i++)
//     {
//         cout<<B[i]<<", ";
//     }

    return 0;
}