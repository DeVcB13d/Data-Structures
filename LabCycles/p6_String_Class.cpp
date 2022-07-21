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
    STR[LEN+1] = '\0';
}

void String::sub_insert(char* subs1,int sublen,int pos)
{
    // Creating a copy of tempstr
    String tempstr(STR,LEN) ;
    LEN = LEN + sublen;
    delete STR;
    STR = new char [LEN+1];
    // Elements before insertion
    for(int i = 0 ; i <= pos ; i++)
    {
        STR[i] = tempstr.STR[i];
    } 
    // Inserting the substring elements
    for(int j = pos ; j <= sublen + 1 ; j++)
    {
        STR[j] = subs1[j - pos];
    }
    // THe elements after insertion
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

void String::showstring()
{
    for(int i = 0 ; i < LEN ; i++)
    {
        cout << STR[i];
    }
    cout << "\n";
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
    cout << "\nMENU : \n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Replace\n";
    cout << "4. Exit\n";
    int choice = 0;
    while(choice != 4 ){
        cout << "\n\nString : ";
        STRM.showstring();
        cout << "Choose an option : ";
        cin >> choice;
        if (choice == 1){
            int SUBLEN;
            cout << "Length of Substring : ";
            cin >> SUBLEN;
            SUB = new char[SUBLEN+1];
            cout << "Enter the Substring to insert : ";
            for(int i = 0 ; i < SUBLEN ; i++)
            {   
                cin >> SUB[i];
            }
            int POS;
            cout << "Enter position to insert : ";
            cin >> POS;
            STRM.sub_insert(SUB,SUBLEN,POS);
        } 
        else if (choice == 2){
            int POS;
            cout << "Enter Position to delete from : ";
            cin >> POS ; 
            int SUBLEN;
            cout << "Length of Subarray to delete : ";
            cin >> SUBLEN;
            STRM.sub_delete(POS,SUBLEN);
        }
        else if (choice == 3)
        {
            int SUBLEN;
            cout << "Length of Substring : ";
            cin >> SUBLEN;
            SUB = new char[SUBLEN+1];
            cout << "Enter the Substring to replace : ";
            for(int i = 0 ; i < SUBLEN ; i++)
            {   
                cin >> SUB[i];
            }
            int POS;
            cout << "Enter position to insert : ";
            cin >> POS;
            STRM.sub_replace(SUB,SUBLEN,POS);
        }
    }



    

    
    //int MI = STRM.get_matching_index(SUB,SUBLEN);
    //cout << "Pattern found at : " << MI << endl;
    return 0;

    // char s1[5] = "abcd";
    // String S1(s1,5);
    // char sub1[3] = "we";
    // char sub2[3] = "hi"; 
    // S1.showstring();
    // S1.sub_insert(sub1,2,1);
    // S1.showstring();
    // // S1.sub_delete(0,3);
    // // S1.showstring();
    // S1.sub_replace(sub2,1,2);
    // S1.showstring();
    
    // return 0;
}