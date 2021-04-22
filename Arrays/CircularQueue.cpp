// front = 0;
// rear = 0;
// front = (front+1)%size
// rear = (rear+1)%size
#include<iostream>
using namespace std;

class CircularQueue
{
private:
    int size, length;
    int front, rear;
    int *A;
public:
    CircularQueue();
    ~CircularQueue();
    int isEmpty();
    int isFull();
    void Enqueue();
    void Dequeue();
    void Display();
};

CircularQueue::CircularQueue()
{
    length = 0;
    front = 0;
    rear = 0;
    cout<<"\nEnter the size of the Queue: ";
    cin>>size;
    A = new int[size];
}

CircularQueue::~CircularQueue()
{
    delete []A;
}

int CircularQueue::isEmpty()
{
    if (rear == front)
    {
        return 1;
    }
    else
        return 0;
    
}

int CircularQueue::isFull()
{
    if((rear+1)%size == front)
    {
        return 1;
    }
    else
        return 0;
    
}

void CircularQueue::Enqueue()
{
    if(isFull())
    {
        cout<<"\nThe Queue is Full";
        return;
    }
    else
    {
        rear = (rear+1)%size;
        cout<<"\nEnter the element: ";
        cin>>A[rear];
        length++;
    }
}

void CircularQueue::Dequeue()
{
    if(isEmpty())
    {
        cout<<"\nThe Queue is Empty";
        return;
    }
    else
    {
        front = (front+1)%size;
        length--;
    }
}

void CircularQueue::Display()
{
    if(isEmpty())
    {
        cout<<"\nThe Queue is Empty";
        return;
    }
    else
    {
        cout<<"\nThe Elements in the Queue are: ";
        int i = front+1;

        do
        {
            cout<<A[i]<<" ";
            i = (i+1)%size;
        } while (i!=(rear+1)%size);
        
        // for(int i = (front+1)%size; i <(rear+1)%size ;i++)
        // {
        //     cout<<A[i]<<" ";
        // }
    }
    
}

int main(int argc, char const *argv[])
{
    CircularQueue cq;
    cout<<"*****ENTER YOUR CHOICE*****"<<endl<<endl;
    cout<<"1 Add elements to circular Queue"<<endl;
    cout<<"2 Disaplay elements of circular Queue"<<endl;
    cout<<"3 Delete element from circular Queue"<<endl;
    cout<<"4 Check if circular Queue is empty"<<endl;
    cout<<"5 Exit"<<endl;
    int choice;
    while(true){
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cq.Enqueue();
                break;
            }
            case 2:{
                cq.Display();
                break;
            }
            case 3:{
                cq.Dequeue();
                break;
            }
            case 4:{
                int t = cq.isEmpty();
                if(t==1){
                    cout<<"\n Circular queue is empty"<<endl;
                }else{
                    cout<<"\n Circular queue is not empty"<<endl;
                }
                break;
            }
            case 5:{
                cout<<"\n*****PROGRAM COMPLETE*****"<<endl;
                exit(0);
                break;
            }
            default:{
                cout<<"Enter correct option"<<endl;
                break;
            }
        }
    }
    return 0;
}
