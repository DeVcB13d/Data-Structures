#include<iostream>
using namespace std;

// Addition of 2 polynomials using array

class polynomial
{
    // 2D Array of coefficients
    // Column 0 -> Power of X
    // Column 1 -> Coefficient of X
    int** P; 
    int Rows;
    public:
        polynomial(){}
        polynomial(int Row)
        {
            Rows = Row ;
            P = new int* [Rows];
            for (int i = 0 ; i <= Rows ; i++)
            {
                P[i] = new int[2];
            }
        }
        // polynomial(polynomial &N)
        // {
        //     Rows = N.Rows;
        //     P = new int* [N.Rows];
        //     for(int i = 0 ; i <= N.Rows ; i++)
        //     {
        //         P[i] = new int[2];
        //         P[i][0] = N.P[i][0];
        //         P[i][1] = N.P[i][1];
        //     }
        // }
        void get_input();
        friend polynomial operator+(polynomial,polynomial);
        void show();
};

void polynomial::get_input()
{
    // Input the entries of the matrix
    // Column 0 -> Power of X
    // Column 1 -> Coefficient of X
    cout << "Enter " << Rows << " entries : \n";
    for(int r = 0 ; r <= Rows ; r++)
    {
        for(int c = 0 ; c < 2 ; c++)
        {
            cin >> P[r][c];
        }
    }
}

polynomial operator+(polynomial P1,polynomial P2)
{
    polynomial P3;
    // Allocating memory for P3
    P3.P = new int*[P1.Rows + P2.Rows];
    for(int j = 0 ; j < P1.Rows + P2.Rows ; j++ ){
        P3.P[j] = new int[2];
    }
    // Declaring an variable to point to the index of P1,P2 and P3 respectively
    int ptr1 = 0 ;int ptr2 = 0 ; int ptr3 = 0; 
    while (ptr1 <= P1.Rows and ptr2 <= P2.Rows){
        if (P1.P[ptr1][0] > P2.P[ptr2][0]){
            P3.P[ptr3][0] = P2.P[ptr2][0];
            P3.P[ptr3][1] = P2.P[ptr2][1];
            ptr2++;ptr3++;
        }      
        else if (P1.P[ptr1][0] < P2.P[ptr2][0]){
            P3.P[ptr3][0] = P1.P[ptr1][0];
            P3.P[ptr3][1] = P1.P[ptr1][1];
            ptr1++;ptr3++;
        }   
        else{
            P3.P[ptr3][0] = P2.P[ptr2][0];
            P3.P[ptr3][1] = P1.P[ptr1][1] + P2.P[ptr2][1];
            ptr1++;ptr2++;ptr3++;
        } 
        //cout << P3.P[ptr3][0] << " " << P3.P[ptr3][1] << "\n";
    }

    if (ptr1 < P1.Rows){
        while (ptr1 <= P1.Rows){
            P3.P[ptr3][0] = P1.P[ptr1][0];
            P3.P[ptr3][1] = P1.P[ptr1][1];
            ptr1++;ptr3++;
        }
    }
    else{
        while (ptr2 <= P2.Rows){
            P3.P[ptr3][0] = P2.P[ptr2][0];
            P3.P[ptr3][1] = P2.P[ptr2][1];
            ptr2++;ptr3++;
        }
    }
    P3.Rows = ptr3;
    return P3;
}

void polynomial::show()
{
    int i; 
    for(i = 0 ; i < Rows ; i++){
        cout << P[i][1] << "X^" << P[i][0] << " + ";
    }
    cout << P[i][1] << "X^" << P[i][0] << "\n";
}

int main()
{
    int T1;
    cout << "Terms of polynomial 1 : ";
    cin >> T1;
    cout << "Enter power and coefficient of polynomial 1 (ascending): \n";
    polynomial P1(T1);
    P1.get_input();
    int T2;
    cout << "Terms of polynomial 2 : ";
    cin >> T2;
    cout << "Enter power and coefficient of polynomial 2 (ascending): \n";
    polynomial P2(T2);
    P2.get_input();
    polynomial P3;
    P3 = P1 + P2 ;
    cout << "P1 : ";
    P1.show();
    cout << "P2 : ";
    P2.show();
    cout << "P1 + P2 : " ;
    P3.show();
}