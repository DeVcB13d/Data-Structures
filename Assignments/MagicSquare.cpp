#include<iostream>
using namespace std;

/* 
A magic square has the sum of its vertical, horizontal and
and diagonal entries as the same number
The magic square algorithm here is designed for odd orders
*/

void generate_Magic_square(int N)
{
    // Dynamically allocating memory for
    // NXN matrix
    int** M = new int* [N];
    for(int i = 0 ; i < N ; i++)
    {
        M[i] = new int [N];
        for(int j = 0;j<N;j++){
            M[i][j] = 0;
        }
    }
    // Initial positions
    int i = N / 2;
    int j = N - 1;
    for (int num = 1; num <= N * N;) 
    {
        if (i == -1 && j == N) 
        {
            j = N - 2;
            i = 0;
        }
        else 
        {
            if (i < 0){
                i = N - 1;
            }
            if (j == N){
                j = 0;
            }
        }
        if (M[i][j] != 0) 
        {
            i++;
            j = j - 2;
            continue;
        }
        else
        {
            num++;
            M[i][j] = num; 
        }
        j++;
        i--; 
    }
    for(int l = 0 ; l < N ; l++ ){
        for(int m = 0 ; m < N ; m++){
            cout << M[l][m] << "\t";
        }
        cout << "\n";
    }

}

int main()
{
    int ON ;
    cout << "Enter the order : ";
    cin >> ON ; 
    generate_Magic_square(ON);
    return 0;
}