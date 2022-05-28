#include<iostream>
using namespace std;

class String
{
        int LEN;
        char* STR;
    public:
        String();
        String(char*,int);
        void showstring();
        void sub_insert(char*,int,int);
        void sub_delete(int,int);
        void sub_replace(char*,int,int);
};

String::String()
{
    LEN = 0;
    STR = new char[LEN];
}

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

void String::sub_insert(char* subs1,int sublen,int pos)
{
    String tempstr(STR,LEN) ;
    LEN = LEN + sublen;
    delete STR;
    STR = new char [LEN+1];
    for(int i = 0 ; i < pos ; i++)
    {
        STR[i] = tempstr.STR[i];
    } 
    for(int j = pos ; j <= sublen ; j++)
    {
        STR[j] = subs1[j - pos];
    }
    for (int k = 0 ; k < LEN-sublen+1 ; k++)
    {
        STR[pos+sublen+k] = tempstr.STR[pos+k];
    }
}

void String::sub_delete(int POS,int SUBLEN)
{
    for(int i = POS ; i <= POS+SUBLEN ; i++)
    {
        STR[i] = STR[i+SUBLEN];
    }
    LEN = LEN - SUBLEN;
}

void String::sub_replace(char* SUB,int POS,int SUBLEN)
{
    for(int i = POS ; i < POS + SUBLEN ; i++ )
    {
        STR[i] = SUB[i-POS];
    }
}
int main()
{
    char s1[5] = "abcd";
    String S1(s1,5);
    char sub1[3] = "we";
    char sub2[3] = "hi"; 
    S1.showstring();
    S1.sub_insert(sub1,2,1);
    S1.showstring();
    // S1.sub_delete(0,3);
    // S1.showstring();
    S1.sub_replace(sub2,1,2);
    S1.showstring();
    
    return 0;
}