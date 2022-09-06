#include<iostream>
using namespace std;

class Circular_queue
{
        int* data;
        int MAX_Size;
    public:
        int front = -1;
        int rear = -1;
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
        for(int i = C.front ; i <= C.MAX_Size ; i++)
        {
            cout << C.data[i] << " ";
        }
        for(int j = 0;j <= C.rear;j++)
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
        if((front == 0 and rear == MAX_Size) or (front == rear + 1))
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

    }
    catch(const char*e)
    {
        cout << e << '\n';
    }
}

int Circular_queue::q_delete(){
    int ret;
    //try
    //{
        if (front == 0){
            cout <<  "QUEUE is empty\n";
        }
        ret = data[front];
        if (front < rear)
            front = front + 1 ; 
        else
            front = 0;
    //}
    //catch(const char*e)
    //{
    //    cout << e << '\n';
    //}
    return ret;    
}

int main()
{
    int MS;
    cout << "Enter maximum size : ";
    cin >> MS ;
    Circular_queue C1(MS);
    cout << "Circular queue operations : ";
    cout << "\n1. Insert\n2. Delete\n3. Print\n";
    int choice = 0;
    while(choice != 4){
        cout << "Select an option : ";
        cin >> choice;
        if (choice == 1)
        {
            int el ;
            cout << "Enter : " ; cin >> el ; 
            C1.q_insert(el);
        }
        else if(choice == 2){
            int ret = C1.q_delete();
            cout << ret << " deleted\n";            
        }
        else if(choice == 3){
            print(C1);
        }
        else{
            cout << "Exit\n";
        }
        print(C1);
        cout << "rear : "<< C1.rear <<endl;
        cout << "front :"<< C1.front <<endl;
    }
}