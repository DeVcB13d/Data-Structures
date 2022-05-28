#include <iostream>
using namespace std;

void substring(char *str,int pos,int L,char* &sub)
{
    sub = new char [L+1];
    for(int i = 0 ; i < L ; i++){
        sub[i] = str[pos+i];
    }
    sub[L+1] = '0';
}

void showstring(char *str,int len)
{
    int i = 0;
    while (str[i] != '0' && i < len)
    {
        cout << str[i] ;
        i++;
    }
    cout << "\n";
}

int main()
{
    int LEN;
    char* STR;
    cout << "Enter string length : ";
    cin >> LEN;
    STR = new char [LEN+1];
    cout << "Enter the string : ";
    for(int i = 0 ; i < LEN ; i++)
    {
        cin >> STR[i];
    }
    STR[LEN+1] = '0';
    cout << "The substrings are : ";
    for(int i = 0; i < LEN ; i++)
    {
        for (int j = 0 ; j <= LEN - i ; j++)
        {
            char* SUB = new char [j];
            substring(STR,i,j,SUB);
            showstring(SUB,j);
            cout << " ";
            delete SUB; 
        }
    }
    // char str1[5] = "abcd";
    // char* s1;
    // showstring(str1,5);
    // substring(str1,0,4,s1);
    // showstring(s1,3);
}