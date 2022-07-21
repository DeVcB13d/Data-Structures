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
        int get_matching_index(char*&,int,int);
        void get_all_matching_indexes(char*&,int);
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

int String::get_matching_index(char* &TEXT,int TLEN,int LB = 0)
{
    int k = LB ;
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

void String::get_all_matching_indexes(char* &TEXT,int TLEN)
{
    int  i = 0 ;
    int ret = 0;
    int searchLB = 0 ;
    int searchTLEN = TLEN ;
    int templen = this->LEN;
    while (ret >= 0 && i < templen ) {
        ret = this->get_matching_index(TEXT,TLEN,searchLB);
        searchLB = searchLB + ret + 1 ;
        LEN = LEN - searchLB ;
        if (ret < 0 && i == 0){
            cout << "Pattern not present\n";
            return;
        }
        else if(ret >= 0)
        {
            cout << ret << "  " ;
        }
        i++;
    }
    LEN = templen;
}

int main()
{
    int LEN;
    char* STR;
    char* SUB;
    cout << "Enter string length : ";
    cin >> LEN;
    STR = new char [LEN+1];
    cout << "Enter the string : ";
    for(int i = 0 ; i < LEN ; i++)
    {
        cin >> STR[i];
    }
    String STRM(STR,LEN);
    STRM.showstring();
    int SUBLEN;
    cout << "Length of Substring : ";
    cin >> SUBLEN;
    SUB = new char[SUBLEN+1];
    cout << "Enter the Substring to Search : ";
    for(int i = 0 ; i < SUBLEN ; i++)
    {
        cin >> SUB[i];
    }
    
    STRM.get_all_matching_indexes(SUB,SUBLEN);

    return 0;
}