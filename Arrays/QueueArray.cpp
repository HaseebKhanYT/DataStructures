#include<iostream>

using namespace std;

class QueueArray
{
private:
    int size, length;
    int *A;
    int front, rear;
public:
    QueueArray(/* args */);
    ~QueueArray();
    int isEmpty();
    int isFull();
    void Enqueue();
    void Dequeue();
    void Display();
};

QueueArray::QueueArray(/* args */)
{
    size = 0;
    length = 0;
    front= -1;
    rear = -1;
    cout<<"\nEnter the size of the Array:";
    cin>>size;
    A = new int[size];
}

QueueArray::~QueueArray()
{
    delete []A;
}

int QueueArray::isEmpty()
{
    if(rear == front)
    {
        return 1;
    }
    else 
        return 0;
}

int QueueArray::isFull()
{
    if(rear == size - 1)
    {
        return 1;
    }
    else 
        return 0;
}

void QueueArray::Enqueue()
{
    if(isFull())
    {
        cout<<"\nThe Queue is Full.";
        return;
    }
    else
    {
        rear++;
        cout<<"\nEnter the element:";
        cin>>A[rear];
        length++;
    }
    
}

void QueueArray::Dequeue()
{
    if(isEmpty())
    {
        cout<<"The Queue is Empty";
        return;
    }
    else
    {
        front++;
        length--;
    }
}

void QueueArray::Display()
{
    if(isEmpty())
    {
        cout<<"The Queue is Empty";
        return;
    }
    else
    {
        cout<<"\nThe Elements of the Queue are:\n";
        for(int i=front+1;i<=rear;i++)
        {
            cout<<A[i]<<" ";        }
    }
}

int main(int argc, char const *argv[])
{
    QueueArray QA;
    QA.Enqueue();
    QA.Enqueue();
    QA.Enqueue();
    QA.Enqueue();
    QA.Display();
    QA.Enqueue();
    QA.Enqueue();
    QA.Dequeue();
    QA.Display();
    QA.Dequeue();
    QA.Display();
    return 0;
}
