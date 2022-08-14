// Saddle point is the minimum (or smallest) element row-wise and maximum 
// (or largest) element column-wise in a matrix

#include<iostream>

int saddle_point(int** M,int R,int C)
{
    
    // Finding the smallest in each row
    for(int i = 0 ; i < R ; i++)
    {
        int s_col = 0 ;
        // Set the smallest element to the First element of the row    
        int s_element = M[i][0] ; 
        // Traversing the ith row
        for(int j = 0 ; j < C ; j++)
        {
            if (M[i][j] < s_element)
            {
                s_element = M[i][j];
                s_col = j;
            } 
        }
        //Check if the smallest element is the largest in the column
        int k = 0;
        while (k < R && M[k][s_col] <= s_element)
        {
            k = k + 1 ;
        }
        //If loop is not exited the k < R
        if (k == R - 1)
        {
            return M[k][s_col] ; 
        }
    }
    return -1;
}

int main()
{
    int uin_rows,uin_cols;
    std::cout << "Enter the rows and colums : ";
    std::cin >> uin_rows >> uin_cols;
    // Dynamically allocate rows for in_mat
    int** in_mat = new int*[uin_rows];
    std::cout << "Enter the matrix : \n"; 
    for(int i = 0 ; i < uin_rows ; i++)
    {
        // Allocating columns
        in_mat[i] = new int[uin_cols];
        for(int k = 0 ; k < uin_cols ; k++)
        {
            std::cin >> in_mat[i][k] ;
        }
    }

    int s_point = saddle_point(in_mat,uin_rows,uin_cols) ;
    if (s_point != -1)
    {
        std::cout << "Saddle point at : " << s_point ;
    }
    else{
        std::cout << "No Saddle point  \n" ;
    }
    return 0;
}