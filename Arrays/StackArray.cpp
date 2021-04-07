#include<iostream>
using namespace std;

class StackArray
{
private:
    
public:
    int length, size, top;
    int *A;

    StackArray();
    ~StackArray();
    void CreateArray();
    int isEmpty();
    int isFull();
    void Push();
    void Pop();
    void Display();
};

StackArray::StackArray()
{
    top = -1;
    length = 0;
    cout<<"\nEnter the size of the Array:";
    cin>>size;
    A = new int[size];

}

StackArray::~StackArray()
{
    delete []A;
}



void StackArray::CreateArray()
{
    do
    {
        if(length>size)
        {
            cout<<"\nPlease Enter a valid length.";
        }
        cout<<"\nEnter the length of the Array:";
        cin>>length;


    }while(length>size);

    for (int i = 0; i < length; i++)
    {
        cout<<"\nEnter A["<<i<<"]: ";
        cin>>A[i];
    }
}


int StackArray::isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int StackArray::isFull()
{
    if(top == size-1)
    {
        return 1;
    }
    else
        return 0;
}
void StackArray::Push()
{
    if(isFull())
    {
        cout<<"\nStackOverflow";
        return;
    }
    else
    {
        top++;
        cout<<"\nEnter the element to be Pushed:";
        cin>>A[top];
        length++;
    }
    
}

void StackArray::Pop()
{
    if(isEmpty())
    {
        cout<<"\nStackUnderflow";
        return;
    }
    else
    {
        cout<<"\nThe element Popped is :"<<A[top];
        top--;
        length--;
    }
}

void StackArray::Display()
{
    if(isEmpty())
    {
        cout<<"\nSTACK IS EMPTY";
        return;
    }
    else
    {
        cout<<"\nThe Elements in the Stack are:\n";
        for(int i = 0; i <length; i++)
        {
            cout<<A[i]<<" ";
        }    
    }
}
int main(int argc, char const *argv[])
{
    StackArray SA;
    SA.Push();
    SA.Push();
    SA.Push();
    SA.Push();
    SA.Push();
    SA.Display();
    SA.Pop();
    SA.Push();
    SA.Display();
    SA.Pop();
    SA.Pop();
    SA.Display();


 

    return 0;
}
