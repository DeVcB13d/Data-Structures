#include<iostream>
#include<cmath>
using namespace std;

class Array
{
        int* DATA;
        int N;
    public:
        Array(int *D,int n)
        {
            DATA = new int[n];
            N = n;
            for(int j = 0;j<N;j++)
            {
                DATA[j] = D[j];
            }
        }
        friend ostream &operator<<(ostream &output,Array A)
        {
            cout << "{";
            for(int i =0;i<A.N;i++)
            {
                cout << A.DATA[i] << ",";
            }
            cout << "}\n";
            return output;
        }
        friend istream &operator>>(istream &input,Array A)
        {
            input >> A.N;
            for(int i=0;i<A.N;i++){
                input >> A.DATA[i];
            }
            return input;
        }
        void Insert(int K,int ITEM);
        int Delete(int K);
        int Linear_Search(int ITEM);
        int Binary_Search(int ITEM);
        int Ternary_Search(int ITEM);
        int interpolation_search(int ITEM);
        int Fibbonacci_Search(int ITEM);
        void Bubble_sort();
        void Radix_sort();
        Array Insertion_sort();
        Array Merge(Array A1,int LBA,Array A2,int LBB,int LBC);
        Array Merge_pass();
        Array Merge_Sort();
};
int Array::interpolation_search(int ITEM)
{
    int LOC = -1;
    int BEG = 1;
    int END = N;
    int POS;
    int LOOPSTEPS = 0;
    while (BEG<=END && ITEM >= DATA[BEG] && ITEM <= DATA[END])
    {
        LOOPSTEPS++;
        POS = BEG + (((ITEM - DATA[BEG])/(DATA[END] - DATA[BEG]))*(END - BEG));
        cout << "POS = " << POS << endl;
        if (ITEM == DATA[POS])
        {
            LOC = POS;
        }
        else if (ITEM > DATA[POS])
        {
            BEG = POS + 1;
        }
        else
        {
            END = POS - 1;
        }
        cout << "BEG = " << BEG << endl;
        cout << "END = " << END << endl;
    }
    cout << "LOOP EXECUTED : " << LOOPSTEPS << endl;
    if (LOC == -1) 
    {
        return -1;
    }
    else 
    {
        return LOC;
    }
    
}
void Array::Insert(int K,int ITEM)
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
int Array::Delete(int K)
{
    int ITEM = DATA[K];
    for(int i=K+1;i<N;i++)
    {
        DATA[i-1] = DATA[i];
    }
    N = N-1;
    return ITEM;
}
int Array::Linear_Search(int ITEM){
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
int Array::Binary_Search(int ITEM){
    //For binary search we assume to have a sorted array
    int BEG = 0;int END = N-1;
    int LOOPSTEPS = 0;
    int MID = (BEG+END)/2;
    while (DATA[MID] != ITEM && (BEG >= 0 && END <= N)){
        LOOPSTEPS++;
        if(DATA[MID]>ITEM){
            END = MID - 1;
        }
        else {
            BEG = MID + 1;
        }
        MID = (BEG+END)/2;
    }
    cout << "LOOP EXECUTED : " << LOOPSTEPS << endl;
    if (DATA[MID] == ITEM)
    {
        return MID;
    }
    else 
        return -1;
}
int Array::Ternary_Search(int ITEM)
{
    int BEG = 0;int END = N;
    int LOOPSTEPS = 0;
    int LOC = -1;
    while (BEG<=END){
        LOOPSTEPS++;
        int MID1 = BEG + ((END-BEG)/3);
        int MID2 = BEG + (2*(END-BEG)/3);
        if(DATA[MID1]==ITEM){
            LOC = MID1;
            break;
        }
        else if (DATA[MID2]==ITEM){
            LOC = MID2;
            break;
        }
        else if (DATA[MID1]>ITEM){
            END = MID1 - 1;
        }
        else if (DATA[MID2]<ITEM){
            BEG = MID2 + 1;
        }
        else
        {
            BEG = MID1 + 1;
            END = MID2 - 1; 
        }
    }
    cout << "LOOP EXECUTED : " << LOOPSTEPS << endl;
    if (LOC == -1){
        return -1;
    }
    else {
        return LOC;
    }
}
void Array::Bubble_sort()
{
    int LOOPSTEPS = 0 ;
    for(int i = 0;i<N-1;i++)
    {
        for(int j = 0;j <= N;j++)
        {
            LOOPSTEPS++;
            if(DATA[j]>DATA[j+1])
            {
                int Temp = DATA[j];
                DATA[j] = DATA[j+1];
                DATA[j+1] = Temp;
            }
        
        }
        cout << "PASS " << i+1 << ": ";
        cout << *this;
    }
    cout << "LOOP EXECUTED : " << LOOPSTEPS << endl;
}
void Array::Radix_sort()
{
    int MAX = DATA[0];
    for(int i=0;i<N;i++)
    {
        if (DATA[i]>MAX)
        {
            MAX = DATA[i];
        }
    }
    int Ndigits = 0;
    int Mtemp = MAX;
    while (Mtemp != 0)
    {
        for(int i=0;i<N;i++)
        {
            int P = pow(10,Ndigits+1);
            int D1 = DATA[i]%P;
            int D2 = DATA[i+1]%P;
            if (D1>D2)
            {
                int Temp = DATA[i];
                DATA[i] = DATA[i+1];
                DATA[i+1] = Temp;
            }
        }
        cout << "PASS " << Ndigits+1 << ": ";
        cout << *this;
        Ndigits++;
        Mtemp/=10;
    }
    cout << *this;
}
int main()
{
    //int D1[6] = {0,1,3,4,5,6};
    int D2[20] = {10,13,15,26,28,50,56,88,94,127,154,356,480,567,689,780,850,956,995};
    int D3[4] = {5,2,3,1};
    Array A3(D3,4);
    cout << A3 ;
    A3.Bubble_sort();
    cout << A3;
    //Array A1(D1,6);
    //Array A1(D2,20);
    //cout << A1;
    //int el;
    //cout << "Enter Element to search : ";cin >> el;
    // for(int el : D2){
    //     cout << "EL = " << el << endl;
    //     cout << A1.Binary_Search(el) << endl;
    //     cout << A1.Ternary_Search(el) << endl;
    // }
    //cout << A1.Binary_Search(el) << endl;
    //cout << A1.Ternary_Search(el) << endl;
    //cout << A1.interpolation_search(el) << endl;
}