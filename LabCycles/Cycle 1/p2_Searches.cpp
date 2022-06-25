#include<iostream>
using namespace std;

class Array 
{
    int* DATA;
    int N;
    int MAXN;
    public:
        Array(int n,int maxn = 100){
            N = n;
            DATA = new int[100];
            MAXN = 100;
        }
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        friend int Linear_Search(Array&,int);
        friend int binary_search(int*,int,int,int);
        void display();
};

void Array::display()
{
    cout << "{";
    for(int i = 0;i<N;i++)
    {
        cout << DATA[i] << ",";
    }
    cout << "}\n";
}

void get_array(int N,Array &A)
{
    cout << "Enter " << N << " elements : \n";
    int val ;
    for(int i = 0;i<N;i++)
    {
        cin >> val ;
        A.set_Data(i,val);
    }
}

int Linear_Search(Array &A,int ITEM)
{
    int LOC = -1;
    for(int i=0;i<A.N;i++)
    {
        if (A.DATA[i]==ITEM)
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
        return -1;
    }
}


int binary_search(int *DATA,int UB,int ITEM,int LB = 0)
{
    //set beg to lower bound
    int BEG = LB;
    //set end to Upper bound
    int END = UB;
    int MID = (BEG + END)/2;
    while(DATA[MID] != ITEM && BEG <= END)
    {
        if (DATA[MID]<ITEM)
        {
            BEG = MID + 1;
        }
        else 
        {
            END = MID - 1;
        }
        MID = (BEG + END)/2;
    }
    if (DATA[MID] == ITEM)
    {
        return MID;
    }
    else
    {
        return -1;
    }   
}

int ternary_search(int* DATA,int UB,int ITEM,int LB = 0)
{
    int BEG = LB;
    int END = UB;
    int MID1,MID2;
    while (BEG<=END){
        MID1 = (END - BEG)/3 + BEG ;
        MID2 = ((2*(END - BEG))/3) + BEG ; 
        cout << "MID1 : " << MID1 << " MID2 : " << MID2 << endl;
        if (DATA[MID1] == ITEM){
            return MID1;
        }
        else if (DATA[MID2] == ITEM){
            return MID2;
        }
        else if (DATA[MID1] > ITEM){
            END = MID1 - 1 ;
        }
        else if (DATA[MID2] < ITEM){
            BEG = MID2 + 1 ;
        }
        else{
            BEG = MID1 + 1 ; 
            END = MID2 - 1 ; 
        } 
    }
    return -1;
}


int main()
{
    int size;
    int Arr[100];
    cout << "Enter the array size : ";cin >> size;
    cout << "Enter the elements : ";
    for(int i = 0; i <size; i++)
    {
        cin >> Arr[i] ;
    }
    Array A1(size);
    A1.display();
    int exit = 1;
    while(exit != 0)
    {
        int Search_elem;
        cout << "Enter the element to search : ";
        cin >> Search_elem;
        //cout << "Hiu\n";
        int ret_index = Linear_Search(A1,Search_elem);
        if (ret_index== -1)
        {
            cout << "Element not found\n" ;
        }
        else 
        {
            cout << "Element " << Search_elem << " found at " << ret_index << endl;
        }
        cout << "Enter 0 to exit : ";
        cin >> exit;
    }
} 