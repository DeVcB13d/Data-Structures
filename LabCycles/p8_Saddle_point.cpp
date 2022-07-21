// Saddle point is the minimum (or smallest) element row-wise and maximum 
// (or largest) element column-wise in a matrix

#include<iostream>
const int tmax = 10;

int saddle_point(int M[tmax][tmax],int R,int C)
{
    //Finding the smallest in each row
    for(int i = 0 ; i < R ; i++)
    {
        // Set the smallest element to the First element of the row    
        int sl = M[i][0] ;
        int s_col = 0 ; 
        // Traversing the ith row
        for(int j = 0 ; j < C ; j++)
        {
            if (M[i][j] < sl)
            {
                sl = M[i][j];
                s_col = j;
            } 
        }
        //Check if the smallest element is the largest in the column
        int k;
        for(k = 0 ; k < R ; k++)
        {
            if (M[k][s_col] > sl)
            {
                // Exit for loop
                k = R ;
            }
        }
        //If loop is not exited the k < R
        if (k < R)
        {
            return M[k][s_col] ; 
        }
    }
    return -1;
}

int main()
{
    int mat[tmax][tmax] = {{1,2,3},{4,5,6},{7,8,9}} ;
    int s_point = saddle_point(mat,3,3) ;
    if (s_point != -1)
    {
        std::cout << "Saddle point at : " << s_point ;
    }
    else{
        std::cout << "No Saddle point  \n" ;
    }
    return 0;
}