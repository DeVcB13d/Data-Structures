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

    int num;
    int row = N/2 ;
    int col = N - 1 ;
    for(num = 1 ; num <=(N*N);)
    {
        if (row == -1 && col != N){
            row = N - 1 ;  
        }
        else if (col == N && row != -1){
            col = 0 ;
        }
        else if (col == N && row == -1){
            col = N - 2 ;
            row = 0 ;
        }
        if (M[row][col] != 0)
        {
            col = col - 2;
            row = row + 1;
        }
        else{
            M[row][col] = num ; 
            num++;
        }
        row = row - 1 ;
        col = col + 1 ;
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