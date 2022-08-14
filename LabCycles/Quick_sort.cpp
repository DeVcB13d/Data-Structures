#include<iostream>
using namespace std;

class Array 
{
    int* DATA;
    int N;
    int MAXN;
    public:
        int PASS = 0 ;
        int LOOPSTEPS = 0;
        int SearchSteps = 0;
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
        friend void get_array(int m,Array &A);
        void set_Data(int index,int D){
            DATA[index] = D;
        }
        void QUICK(int BEG,int END,int& LOC);
        void QUICKSORT();
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



void Array::QUICK(int BEG,int END,int& LOC)
{
    int LEFT = BEG;
    int RIGHT = END;
    LOC = BEG;
    // Inner pass to check
    int IP = 0;
    while (RIGHT >= LEFT)
    {
        // Scanning from RIGHT TO LEFT
        while (DATA[LOC] <= DATA[RIGHT] && RIGHT!= BEG){
            RIGHT--;
        }
        if(RIGHT==BEG || RIGHT <= LEFT){
            return;
        }
        else if(DATA[LOC] > DATA[RIGHT]){
            int temp = DATA[LOC];
            DATA[LOC] = DATA[RIGHT];
            DATA[RIGHT] = temp;
            LOC = RIGHT;
            RIGHT = RIGHT - 1 ;
        }
        cout << "IP RL" << IP << " : ";
        this->display();
        IP++;
        // Scanning from LEFT to RIGHT
        while (DATA[LOC] >= DATA[LEFT] && LEFT != END){
            LEFT++;
        }
        if(LEFT == END || RIGHT <= LEFT){
            return;
        }
        else if(DATA[LOC] < DATA[LEFT]){
            int temp = DATA[LOC];
            DATA[LOC] = DATA[LEFT];
            DATA[LEFT] = temp;
            LOC = LEFT;
            LEFT = LEFT + 1 ;
        }
        cout << "IP LR" << IP << " : ";
        this->display();
        IP++;
    }
}

void Array::QUICKSORT()
{
    int TOP = 0;
    // Initialise UPPER and LOWER stacks
    int* LOWER;
    int* UPPER;
    if (N > 1){
        LOWER = new int[N];
        UPPER = new int[N];
        TOP = 0;
        LOWER[TOP] = 0;
        UPPER[TOP] = N-1;
    }
    int BEG,END,LOC;
    while (TOP != -1){
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP--;
        this->QUICK(BEG,END,LOC);
        cout << "\nPASS " << this->PASS << " : ";
        this->display();
        PASS++;
        if (BEG < LOC-1){
            TOP++;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC-1;
        }
        if (LOC+1 < END){
            TOP++;
            LOWER[TOP] = LOC+1;
            UPPER[TOP] = END;
        }
    }
}

int main()
{
    Array A(100);
    int Nels;
    cout << "Elements in Array : ";
    cin >> Nels;
    get_array(Nels,A);
    cout << "Before Sorting : ";
    A.display();
    cout << "After Sorting  : ";
    A.QUICKSORT();
    A.display();
}

