#include<iostream>

void fact(int& FACT,int N)
{
    if (N == 0){
        FACT = 1;
        return;
    }
    else{
        fact(FACT,N-1);
        FACT = N*FACT;
    }
}

int main()
{
    int f,n;
    std::cout << "Enter : ";
    std::cin >> n;
    fact(f,n);
    std::cout << "fact = " << f << "\n"; 
}