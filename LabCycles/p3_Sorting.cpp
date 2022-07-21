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
        void Bubble_sort();
        void selection_sort();
        void insertion_sort();
        void Merge();
        void Merge_sort();
        void display();

};


void Array::Bubble_sort()
{
    int LB = 1;
    int UB = N;
    PASS = 0;LOOPSTEPS = 0;
    //To control the passes (N - 1)
    for(int i = LB ; i < UB ; i ++ )
    {
        PASS++;
        // Inner loop to traverse and exchange
        // for each pass
        for(int j = 0 ; j < UB - i ; j++)
        {
            LOOPSTEPS++;
            if (DATA[j] > DATA[j+1])
            {
                int temp = DATA[j];
                DATA[j] = DATA[j+1];
                DATA[j+1] = temp;
            }
        }
    }
}

void Array::selection_sort()
{
    int LB = 0;
    int UB = N;
    PASS = 0;LOOPSTEPS = 0;
    for(int i = 0 ; i < UB ; i++)
    {
        PASS++;
        for (int j = i + 1 ; j < UB ; j++)
        {
            LOOPSTEPS++;
            if (DATA[i] > DATA[j]) 
            {
                int temp = DATA[j];
                DATA[j] = DATA[i];
                DATA[i] = temp;
            }
        }
    }
}

void Array::insertion_sort()
{
    int LB = 0;
    int UB = N;
    PASS = 0;LOOPSTEPS = 0;
    int ptr;
    for(int i = LB + 1 ; i < UB ; i++ )
    {
        PASS ++;
        int ptr = i - 1;
        int temp = DATA[i];
        while (ptr >= 0 && temp < DATA[ptr]) 
        {
            LOOPSTEPS++;
            DATA[ptr+1] = DATA[ptr] ;
            ptr-- ;
        }
        DATA[ptr+1] = temp ;
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
    A.DATA = new int [A.N];
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
    // MENU
    cout << "MENU : \n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Input a new array\n";
    int choice = 0;
    while (choice != 6)
    {
        cout << "Choose an option : ";
        cin >> choice;
        Array A_temp = Array(A1);
        if (choice==1)
        {
            cout << "Before Sorting : ";
            A1.display();
            A1.Bubble_sort();
            cout << "After sorting : ";
            A1.display();
            cout << "PASSES : " << A1.PASS << endl ;
            cout << "STEPS : " << A1.LOOPSTEPS << endl ;
        }
        else if (choice==2)
        {
            cout << "Before Sorting : ";
            A1.display();
            A1.selection_sort();
            cout << "After sorting : ";
            A1.display();
            cout << "PASSES : " << A1.PASS << endl ;
            cout << "STEPS : " << A1.LOOPSTEPS << endl ;
        }
        else if (choice==3)
        {
            cout << "Before Sorting : ";
            A1.display();
            A1.insertion_sort();
            cout << "After sorting : ";
            A1.display();
            cout << "PASSES : " << A1.PASS << endl ;
            cout << "STEPS : " << A1.LOOPSTEPS << endl ;
        }
        else if (choice==4)
        {
            cout << "Before Sorting : ";
            A1.display();
            //A1.Merge_sort();
            cout << "After sorting : ";
            A1.display();
            cout << "PASSES : " << A1.PASS << endl ;
            cout << "STEPS : " << A1.LOOPSTEPS << endl ;
        }
        else if (choice==5)
        {
            int n;
            cout << "Enter the array size : ";
            cin >> n;
            get_array(n,A1);
        }
        else if(choice==6)
        {
            cout << "Exiting>>>>>>>>>>\n";
        }
        A1 = A_temp;
    }


    return 0;
}