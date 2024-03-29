#include <iostream>
using namespace std;

class Array 
{
        int* DATA;
        int N;
        int MAXN;
    public:
        int PASS = 0 ;
        int LOOPSTEPS = 0;
        Array(int maxn = 100){
            DATA = new int[100];
            MAXN = 100;
        }
        Array(Array &A){
            this->N = A.N;
            DATA = new int[A.MAXN];
            MAXN = A.MAXN;
            for(int i = 0 ; i < N ; i++){
                DATA[i] = A.DATA[i];
            } 
        }
        void setels(int els){N = els;}
        friend void get_array(int m,Array &A);
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        void display();
        friend void Merge(Array &A,int EA,int LBA,Array &B,int EB,int LBB,Array &C,int LBC);
        friend void MergePass(Array &A,int N,int L,Array &B);
        void MergeSort(); 
};
int LOOPSTEPS = 0;
// Merge 2 sorted arrays A and B into a sorted array C
void Merge(Array &A,int EA,int LBA,Array &B,int EB,int LBB,Array &C,int LBC){
    // Pointers to the TOP of A,B and C
    LOOPSTEPS++;
    int PTRA = LBA;
    int PTRB = LBB;
    int PTRC = LBC;
    // Upper bounds
    int UBA = LBA + EA - 1  ;
    int UBB = LBB + EB - 1  ;
    while (PTRA <= UBA && PTRB <= UBB){
        // Insert the shortest element to C
        if (A.DATA[PTRA] < B.DATA[PTRB])
        {
            C.DATA[PTRC] = A.DATA[PTRA] ;
            PTRC++;
            PTRA++;
        }
        else
        {
            C.DATA[PTRC] = B.DATA[PTRB] ;
            PTRB++;
            PTRC++;
        }
    }
    // Add the non exhausted list to C
    if (PTRA > UBA){
        for(int i = 0 ; i <= UBB - PTRB; i++){
            C.DATA[PTRC+i] =  B.DATA[PTRB+i];
        }
    }
    else{
        for(int i = 0 ; i <= UBA - PTRA ; i++){
            C.DATA[PTRC+i] = A.DATA[PTRA+i];
        }
    }   
   // A.display();
   // B.display();
}

void MergePass(Array &A,int N,int L,Array &B){
    // L - elements in subarray
    // Q - Number of sub arrays
    int Q = N/(2*L) ;
    // S - Index of Elements that does not fit
    int S = 2*L*Q ;
    // R - Number of Balance elements
    int R = N - S ;
    cout << "L : " << L << endl;
    cout << "Q : " << Q << endl;
    cout << "S : " << S << endl;
    cout << "R : " << R << endl;
    for(int j = 1 ; j <= Q ; j++){
        int LB = (2*j - 2)*L ; 
        Merge(A,L,LB,A,L,(LB+L),B,LB);
        cout << "B : ";
        B.display();
        cout << "Under Merge Pass  : ";
        cout << "\nA : ";
        A.display();
        cout << "B : ";
        B.display();
    }
    if (R <= L){
        for (int j = 0 ; j < R;j++){
            B.DATA[S+j] = A.DATA[S+j];
        }
    }
    else{
        Merge(A,L,S,A,R-L,L+S,B,S);
    }
    // A.display();
    // B.display();
}

void Array::MergeSort(){
    int L = 1;
    // Copying A to B
    Array B(100);
    // cout << "B copied as : ";
    // B.display();
    // B.DATA = new int[N] ;
    B.N = N ;
    while (L < N){
        PASS++;
        MergePass(*this,N-1,L,B);
        PASS++;
        MergePass(B,N-1,2*L,*this);
        L = 4 * L ;
    }
    
}

void Array::display()
{
    cout << "{";
    for(int i = 0;i<N;i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

void get_array(int m,Array &A)
{
    A.N = m;
    cout << "Enter " << A.N << " elements : \n";
    int val ;
    for(int i = 0;i<A.N;i++)
    {
        cin >> val ;
        A.set_Data(i,val);
    }
}


int main()
{
    Array A1(100);
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    get_array(n,A1);
    cout << "Before Sorting : ";
    A1.display();
    A1.MergeSort();
    cout << "After sorting : ";
    A1.display();
    cout << "PASSES : " << A1.PASS << endl ;
    cout << "STEPS : " << LOOPSTEPS << endl ;
}