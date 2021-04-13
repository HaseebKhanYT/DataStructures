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
    cout<<"\nEnter the size of the Queue";
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
    CircularQueue CQ;
    CQ.Enqueue();
    CQ.Enqueue();
    CQ.Enqueue();
    CQ.Enqueue();
    CQ.Enqueue();
    CQ.Display();
    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Display();
    CQ.Dequeue();
    CQ.Enqueue();
    CQ.Dequeue();
    CQ.Display();
    CQ.Enqueue();
    CQ.Display();

    return 0;
}
