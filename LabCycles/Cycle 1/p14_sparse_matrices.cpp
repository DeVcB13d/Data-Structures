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
        void T(SparseMatrix&);
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

void SparseMatrix::T(SparseMatrix &X)
{
    X.M[0][0] = this->M[0][1];
    X.M[0][1] = this->M[0][0];
    X.M[0][2] = this->M[0][2];
    int k = 1;
    int N = this->M[0][2];
    for(int i = 0 ; i < M[0][1] ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if (M[j][1] == i)
            {
                X.M[k][0] = i;
                X.M[k][1] = M[j][0];
                X.M[k][2] = M[j][2];
                k++;
            }
        }
    }
}

int main()
{
    
}