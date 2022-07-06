#include<iostream>
using namespace std;

class polynomial
{
    // Array of coefficients
    // int increasing power order of coefficient
    int* C; 
    int power;
    public:
        polynomial(){}
        polynomial(int pow,int* Arr)
        {
            power = pow;
            // power + 1 constant
            C = new int [power+1];
            for(int i = 0 ; i < pow ; i++)
            {
                C[i] = Arr[i];
            }
        }
        polynomial(polynomial &P)
        {
            power = P.power;
            // power + 1 constant
            C = new int [power+1];
            for(int i = 0 ; i < power ; i++)
            {
                C[i] = P.C[i];
            }
        }
        friend polynomial operator+(polynomial,polynomial);
        void show();
};

polynomial operator+(polynomial P1,polynomial P2)
{
    polynomial P3;
    // lower power,greater power
    int lp,gp;
    // Set power of output to larger polynomial
    if (P1.power > P2.power)
    {
        P3.power = P1.power;
        lp = P2.power;
        gp = P1.power;
        P3.C = new int [P3.power+1];
        for(int k = lp ; k < gp ; k++)
        {
            P3.C[k] = P1.C[k];
        }
    }
    else{
        P3.power = P2.power; 
        lp = P1.power;
        gp = P2.power;
        for(int k = lp ; k < gp ; k++)
        {
            P3.C[k] = P2.C[k];
        }
    }
    // Adding common terms
    for(int j = 0 ; j < lp ;j++)
    {
        P3.C[j] = P1.C[j] + P2.C[j] ;
    }
    return P3;
}

void polynomial::show()
{
    for(int i = 0 ; i < power+1 ; i++){
        cout << C[i] << "X^" << i << " + ";
    }
    cout << "\n";
}
int main()
{
    int pow1;
    cout << "Power of polynomial 1 : ";
    cin >> pow1;
    int* Arr = new int[pow1+1];
    cout << "Enter terms of polynomial 1 : ";
    for(int i = 0 ; i < pow1+1;i++)
    {
        cin >> Arr[i];
    }
    polynomial P1(pow1,Arr);
    int pow2;
    cout << "Power of polynomial 2 : ";
    cin >> pow2;
    int* Arr2 = new int[pow2+1];
    cout << "Enter terms of polynomial 2 : ";
    for(int i = 0 ; i < pow1+1;i++)
    {
        cin >> Arr2[i];
    }
    polynomial P2(pow2,Arr2);

    polynomial P3 = P1 + P2 ;
    cout << "P1 : ";
    P1.show();
    cout << "P2 : ";
    P2.show();
    cout << "P1 + P2 : " ;
    P3.show();
}