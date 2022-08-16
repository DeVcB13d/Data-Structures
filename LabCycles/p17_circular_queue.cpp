#include<iostream>
using namespace std;

class Circular_queue
{
        int* data;
        int front = -1;
        int rear = -1;
        int MAX_Size;
    public:
        Circular_queue(int size){
            MAX_Size = size;
            data = new int[MAX_Size];
        }
        friend void print(Circular_queue &C);
        void q_insert(int item);
        int q_delete();

};

void print(Circular_queue &C)
{
    // In case of the list going into circular after Max_size
    if (C.rear < C.front)
    {
        for(int i = C.front ; i < C.MAX_Size ; i++)
        {
            cout << C.data[i] << " ";
        }
        for(int j = 0;j < C.rear;j++)
        {
            cout << C.data[j] << " ";
        }    
    }
    else
    {
        for(int i = C.front ; i <= C.rear ; i++)
        {
            cout << C.data[i] << " ";
        }
    }
    cout << "\n";
}

void Circular_queue::q_insert(int item)
{
    try
    {
        // When the front and rear are next to each other
        if((front == 1 and rear == MAX_Size) or (front == rear + 1))
        {
            throw "OVERFLOW";
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if(rear == MAX_Size)
        {
            rear = 0;
        }
        else 
        {
            rear = rear + 1;
        }
        data[rear] = item;
        cout << "rear : "<< rear << " " << data[rear] << endl;
        cout << front << "F :\n";
    }
    catch(const char*e)
    {
        cout << e << '\n';
    }
}



int main()
{
    Circular_queue C1(30);
    int el;
    cout << "ENTER : ";
    for(int k = 0 ; k < 4 ; k++)
    {
        cin >> el;
        C1.q_insert(el);
    }
    print(C1);
}