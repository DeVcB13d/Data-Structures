#include<iostream>
using namespace std;

class Array 
{
    int* DATA;
    int N;
    int MAXN;
    public:
        int SearchSteps = 0;
        Array(int maxn = 100){
            DATA = new int[100];
            MAXN = 100;
        }
        friend void get_array(int m,Array &A);
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        int Linear_Search(int);
        int binary_search(int);
        int ternary_search(int);
        int interpolation_search(int);
        int ternary_search(int);
        int interpolation_search(int);
        int Fibbonacci_Search(int);
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

int Array::Linear_Search(int ITEM)
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
        return -1;
    }
}

int Array::binary_search(int ITEM)
{
    SearchSteps = 0;
    int UB = N;
    int LB = 0;
    //set beg to lower bound
    int BEG = LB;
    //set end to Upper bound
    int END = UB;
    int MID = (BEG + END)/2;
    while(DATA[MID] != ITEM && BEG <= END)
    {
        SearchSteps++;
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

int Array::ternary_search(int ITEM)
{
    SearchSteps = 0;
    int BEG = 0;
    int END = N;
    int MID1,MID2;
    while (BEG<=END){
        SearchSteps++;
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

int Array::interpolation_search(int ITEM)
{
    SearchSteps = 0;
    int BEG = 0 ;
    int END = N ;
    int POS;
    while (BEG <= END && (ITEM >= DATA[BEG] && ITEM <= DATA[END]))
    {
        SearchSteps++;
        POS = BEG + (ITEM - DATA[BEG])/(DATA[BEG] - DATA[END])*(END - BEG);
        if (DATA[POS] == ITEM)
        {
            return POS;
            break;
        }
        else if (DATA[POS] > ITEM)
        {
            END = POS - 1 ;
            break;
        }
        else
        {
            BEG = POS + 1 ;
        }
    }
    return -1 ; 
}

int Array::Fibbonacci_Search(int ITEM)
{
    SearchSteps = 0;
    int UB = N;
    int LB = 0;
    int F2 = 0 ;
    int F1 = 1 ;
    int Fb = 1 ;
    int offset = -1 ;
    //To get the 3 fibonacci less than UB
    while (Fb < UB)
    {
        F2 = F1 ;
        F1 = Fb ;
        Fb = F1 + F2 ;
    }
    while (Fb > 1)
    {
        SearchSteps++;
        int i = offset + F2;
        if (DATA[i] > ITEM)
        {
            F2 = F1 ;
            F1 = Fb ;
            Fb = F1 + F2 ;
            offset = i ;
        }
        else if (DATA[i] < ITEM)
        {
            Fb = F2 ;
            F1 = F1 - F2 ;
            F2 = Fb - F1 ;
        }
        else
        {
            return i ;
        }
    }
    if (F1 == 1 && DATA[offset + 1] == ITEM)
    {
        return offset + 1;
    }
    return -1 ;
}




int main()
{
    Array A1(100);
    
    cout << "Menu : \n";
    cout << "1. input"
} 