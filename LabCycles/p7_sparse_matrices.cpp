//class to represent triplets
#include<iostream>
using namespace std;

class SparseMatrix
{
        // Number of Non Zero Entries
        int NonZero;
        int** M;
    public:
        SparseMatrix(){}
        SparseMatrix(int N);
        void Set_Sparse_Matrix();
        void display();
        friend SparseMatrix operator+(SparseMatrix,SparseMatrix);
        void T(SparseMatrix&);
};

SparseMatrix::SparseMatrix(int N)
{
    // A Sparse matrix has 3 colums
    // Rows depend on number of Non-Zero entries
    NonZero = N ;
    M = new int*[NonZero];
    for(int i = 0 ; i < NonZero ; i++)
    {
        M[i] = new int[3];
    }
}

// To get the User input of the sparse matrix
void SparseMatrix::Set_Sparse_Matrix()
{
    // The First input will be -
    // ROW - COL - NONZERO
    // Then input the entries of the matrix
    cout << "Enter the entries : \n";
    for(int r = 0 ; r < NonZero ; r++)
    {
        for(int c = 0 ; c < 3 ; c++)
        {
            cin >> M[r][c];
        }
    }
}

// Method to print the sparse matrix
void SparseMatrix::display()
{
    for(int i = 0 ; i < NonZero ; i++)
    {
        for(int j = 0 ; j < 3 ; j++ )
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}

// To get the transpose of *this to a matrix X
void SparseMatrix::T(SparseMatrix &X)
{
    // The Rows and cols of X are the reverse of M
    X.M[0][0] = this->M[0][1];
    X.M[0][1] = this->M[0][0];
    // Non zero entries remain the same
    X.M[0][2] = this->M[0][2];
    int k = 1;
    // N -> Non zero entries
    int N = this->M[0][2];
    // Columns
    for(int i = 0 ; i < M[0][1] ; i++)
    {
        for(int j = 1 ; j < N ; j++)
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

SparseMatrix operator+(SparseMatrix A,SparseMatrix B)
{
    //Check if the dimensions are the same
    if (A.M[0][0] != B.M[0][0] || A.M[0][1] != B.M[0][0])
    {
        cout << "Error : Incompatible dimensions\n";
        SparseMatrix C(0);
        return C;
    }
    int Alen = A.NonZero;
    int Blen = B.NonZero;
    // Since we dont know the total nonzero
    // entries in C , giving it its max value
    SparseMatrix C(Alen+Blen);
    int i,j,k = 1;
    //Set the first row of C
    C.M[0][0] = A.M[0][0];
    C.M[0][1] = A.M[0][1];
    while(i <= Alen && j <= Blen)
    {
        if ((A.M[i][0] > B.M[j][0]) || 
            (A.M[i][0]==B.M[j][0] && A.M[i][1] > B.M[j][1]))
        {
            C.M[k][0] = B.M[j][0];
            C.M[k][1] = B.M[j][1];
            C.M[k][2] = B.M[j][2];
            k++;j++;
        }
        else if((A.M[i][0] < B.M[j][0]) || 
            (A.M[i][0] == B.M[j][0] && A.M[i][1] < B.M[j][1]))
        {
            C.M[k][0] = A.M[i][0];
            C.M[k][1] = A.M[i][1];
            C.M[k][2] = A.M[i][2];
            k++;i++;
        }
        else
        {
            C.M[k][0] = A.M[i][0];
            C.M[k][1] = A.M[i][1];
            C.M[k][2] = A.M[j][2] + B.M[i][2] ;
            k++;i++;j++;
        }
    }

    while(i <= Alen)
    {
        C.M[k][0] = A.M[i][0];
        C.M[k][1] = A.M[i][1];
        C.M[k][2] = A.M[i][2];
        k++;i++;
    }
    while(j <= Blen)
    {
        C.M[k][0] = B.M[j][0];
        C.M[k][1] = B.M[j][1];
        C.M[k][2] = B.M[j][2];
        k++;j++;        
    }
    C.M[0][2] = k - 1;
    C.NonZero = k - 1;
    return C ;
}


int main()
{
    int len1,len2;
    cout << "Enter the rows in sparse matrix 1 and 2: ";
    cin >> len1 >> len2 ;
    SparseMatrix S1(len1);
    S1.Set_Sparse_Matrix();
    SparseMatrix S2(len2);
    S2.Set_Sparse_Matrix();
    // cout << "S1  : \n";
    // S1.display();
    // cout << "S2  : \n";
    // S2.display();
    SparseMatrix S3 = S1 + S2 ;
    cout << "S3  : \n";
    S3.display();
    cout << "Transposes : \n";
    SparseMatrix S4;
    S1.T(S4);
    S4.display();
    return 0;
}