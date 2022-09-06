#include<iostream>
class Pterm
{
    public:
        int coefficient;
        int power;
        // Link to the next term
        Pterm* link;
};

class polynomial
{
    // Polynomial terms are taken in ascending order
    // of their power
        Pterm* start;
        int degree;
    public:
        // get user input of the terms
        void get_terms(int);
        // print the polynomial
        friend void print(polynomial &p);
        // Add 2 polynomials
        friend polynomial operator+(polynomial,polynomial);
};

void polynomial::get_terms(int degree)
{
    this->degree = degree;
    std::cout << "Enter " << degree + 1 << " terms : ";
    int cf_in;
    std::cin >> cf_in ;
    start = new Pterm() ;
    start->coefficient = cf_in ;
    start->power = 0;
    // save the previous node to create the link
    Pterm* save = start;
    // creating new node    
    Pterm* tnew;
    for(int i = 1 ; i <= degree ; i++)
    {
        std::cin >> cf_in ;
        tnew = new Pterm();
        tnew->coefficient = cf_in;
        tnew->power = i;
        save->link = save;
        save = tnew ;
    }
    tnew->link = 0;
}

void print(polynomial &p)
{
    Pterm* P = p.start;
    while(P->link != 0)
    {
        if(P->coefficient != 0)
        {
            std::cout << P->coefficient << "x^" << P->power << " + "; 
        } 
        P = P->link;
    }
    std::cout << "\n"; 
}

polynomial operator+(polynomial P1,polynomial P2)
{
    Pterm* ptr1,ptr2,ptr3;
    ptr1 = P1.start;
    ptr2 = P2.start
    polynomial P3

}

int main()
{
    int deg;
    std::cout << "Enter the degree : ";
    std::cin >> deg ;
    polynomial P1;
    P1.get_terms(deg);
    print(P1);
}