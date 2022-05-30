#include<iostream>
using namespace std;

class String
{
        int LEN;
        char* STR;
    public:
        String(){}
        String(char*,int);
        void showstring();
        int get_matching_index(char*,int);
};

String::String(char* str,int len)
{
    LEN = len;
    STR = new char [LEN];
    for (int i = 0 ; i < len ; i++)
    {
        STR[i] = str[i];
    }
    STR[LEN+1] = '0';
}

void String::showstring()
{
    for(int i = 0 ; i < LEN ; i++)
    {
        cout << STR[i];
    }
    cout << "\n";
}

int String::get_matching_index(char* TEXT,int TLEN)
{
    int k = 0 ;
    int max = LEN - TLEN + 1;
    while (k <= max)
    {
        int count = 0;
        for(int i = 0 ; i < TLEN ; i++)
        {
            if (TEXT[i] != STR[k+i])
            {
                i = TLEN ;
            }
            else
            {
                count++;
            }
        }
        if (count==TLEN)
        {
            return k ;
        }
        k++;
    }
    return -1;
}

int main()
{
    char p1[9] = "AABABCBA";
    String P(p1,8);
    char T1[4] = "AB" ;
    P.showstring();
    int MI = P.get_matching_index(T1,2);
    cout << "Pattern found at : " << MI << endl;
    return 0;
}