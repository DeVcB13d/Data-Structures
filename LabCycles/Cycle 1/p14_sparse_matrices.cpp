//class to represent triplets
#include<iostream>
using namespace std;

class SparseMatrix
{
        int NonZero;
        int** M;
    public:
        SparseMatrix(int N);
        void Set_Sparse_Matrix();
        void display();
        friend SparseMatrix operator+(SparseMatrix,SparseMatrix);
        SparseMatrix T();
};

SparseMatrix::SparseMatrix(int N)
{
    NonZero = N ;
    M = new int*[NonZero];
    for(int i = 0 ; i < NonZero ; i++)
    {
        M[i] = new int[3];
    }
}

void SparseMatrix::Set_Sparse_Matrix()
{
    cout << "Enter the entries : ";
    for(int r = 0 ; r < NonZero ; r++)
    {
        for(int c = 0 ; c < 3 ; c++)
        {
            cin >> M[r][c];
        }
    }
}

SparseMatrix SparseMatrix::T()
{
    Spa
}