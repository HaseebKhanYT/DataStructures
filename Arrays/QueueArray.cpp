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
        cout<<"The Queue is Full.";
        return;
    }
    else
    {
        rear++;
        cout<<"Enter the element:";
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
        cout<<"The Elements of the Queue are:\n";
        for(int i=front+1;i<=rear;i++)
        {
            cout<<A[i]<<" ";        }
    }
}

int main(int argc, char const *argv[])
{
    QueueArray qa;
    cout<<"*****ENTER YOUR CHOICE*****"<<endl<<endl;
    cout<<"1 Enqueue"<<endl;
    cout<<"2 Dequeue"<<endl;
    cout<<"3 Display Queue"<<endl;
    cout<<"4 Check if queue is empty"<<endl;
    cout<<"5 Exit"<<endl;
    int choice;
    while(1){
        cout<<"\n\n Enter your choice: "; 
        cin>>choice;
        switch(choice){
            case 1:{
                qa.Enqueue();
                break;
            }
            case 2:{
                qa.Dequeue();
                break;
            }
            case 3:{
                qa.Display();
                break;
            }
            case 4:{
                if(qa.isEmpty()){
                    cout<<"\nQueue is empty"<<endl;
                }else{
                    cout<<"\nQueue is not empty"<<endl;
                }
                break;
            }
            case 5:{
                cout<<"\n \t*****PROGRAM COMPLETE\n"<<endl;
                exit(0);
                break;
            }
            default:{
                cout<<"\nEnter correct choice"<<endl;
                break;
            }
        }
    }
    return 0;
}
