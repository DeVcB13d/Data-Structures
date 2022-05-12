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
        }
        int interpolation_search(int ITEM)
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
        int Fibbonacci_Search(int ITEM)
        {

        }
};

int main()
{
    int D1[21] = {0,10,13,15,26,28,50,56,88,94,125,159,356,480,516,689,699,718,850,956,995};
    Array A1(D1,21);
    cout << A1.interpolation_search(28) << endl;;
}