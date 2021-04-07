#include<iostream>

using namespace std;

class DynamicArray
{
public:
        int size, length;
        int *A;

    DynamicArray() {}
    ~DynamicArray() {delete []A;}
    void Create();
    void Display();
    void Add(int ele);
    void Insert(int index, int x);
    void SortedInsert(int x);
    void Delete(int index);
    int LSearch(int key);
    int BSearch(int key);
    int RBSearch(int l,int h, int key);
    int Get(int index);
    void Set(int index,int x);
    int Max();
    int Min();
    int Sum();
    int RSum(int n);
    int Avg();
    void Reverse();
    void Swap(int *x, int *y);
    void SwapReverse();


};

void DynamicArray::Create()
{
    length = 0;
    size = 0;
    cout<<"Enter the Size of the Array: ";
    cin>>size;
    A = new int[size];
    cout<<"Enter the Number of elements: ";
    cin>>length;
    cout<<"Enter the elements: ";
    for (int i = 0; i < length; i++)
    {
        cin>>A[i];
    }
    cout<<"\nCreation Successful...\n"<<endl;
    

}

void DynamicArray::Display()
{
    cout<<"The size of the Array is "<<size<<"."<<endl;
    cout<<"The length of the Array is "<<length<<"."<<endl;
    cout<<"The Array: "<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
}

void DynamicArray::Add(int ele)
{
    if (length<size)
    {
        A[length] = ele;
        cout<<"\nAdded "<<ele<<" Successfully at Index = "<<length<<endl;
        length++;
    }
    
}

void DynamicArray::Insert(int index, int x)
{
    for(int i=length;i>index;i--)
    {
        A[i] = A[i-1];
    }
    A[index] = x;
    cout<<"Inserted "<<x<<" at index "<<index<<endl;
    length++;
}

void DynamicArray::SortedInsert(int x)
{
    int i = length-1;
    while (A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    cout<<"Inserted "<<x<<" at index "<<i+1<<endl;
    length++;
}

void DynamicArray::Delete(int index)
{
    int x = A[index];
    for (int i = index; i < length; i++)
    {
        A[i]=A[i+1];
    }
    cout<<"\n The Deletion of "<<x<<" was succesful"<<endl;
    length--;
    

}

int DynamicArray::LSearch(int key)
{
    for (int i =0;i<length;i++)
    {
        if(key==A[i])
        {
            return i;
        }
        
    }
    return -1;
}

int DynamicArray::BSearch(int key)
{
    int l,h,m;
    l = 0, h = length - 1;
    while (l<=h)
    {
        m = (l+h)/2;
        if(key == A[m])
        {
            return m;
        }
        else if (key>A[m])
        {
            l=m+1;
        }
        else
        {
            h = m-1;
        }
    }
    if(l>h)
        return -1;
    
}

int DynamicArray::RBSearch(int l,int h, int key)
{
    if(l<=h)
    {
        int m = (l+h)/2;
        if (key == A[m])
        {
            return m;
        }
        else if (key>A[m])
        {
            return RBSearch(m+1,h,key);
        }
        else
        {
            return RBSearch(l,m-1,key);
        }
    }
    else
        return -1;
}

int DynamicArray::Get(int index)
{
    if(index>=0&&index<length)
        return A[index];
    else
        cout<<"Invalid Index"<<endl;
        return -1;
}

void DynamicArray::Set(int index,int x)
{
    if(index>=0&&index<length)
        A[index] = x;

}

int DynamicArray::Max()
{
    int max;
    max = A[0];
    for (int i=1;i<length;i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

int DynamicArray::Min()
{
    int min;
    min = A[0];
    for (int i=1;i<length;i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

int DynamicArray::Sum()
{
    int sum = 0;
    for(int i = 0;i<length;i++)
    {
        sum+=A[i];
    }
    return sum;
}

int DynamicArray::RSum(int n)
{
    if(n<0)
        return 0;
    else
        return RSum(n-1) + A[n];

}

int DynamicArray::Avg()
{
    int sum = 0;
    for(int i = 0;i<length;i++)
    {
        sum+=A[i];
    }
    return sum/length;
}

void DynamicArray::Reverse()
{
    int j, B[size];
    for(int i=length-1,j=0 ; i>=0 ; i--, j++)
    {
        B[j] = A[i];
        
    }

    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
    
}

void DynamicArray::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void DynamicArray::SwapReverse()
{
    int j;
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        Swap(&A[i],&A[j]);
    }

}











int main()   //Main Function
{
    DynamicArray Arr;
    Arr.Create();
    Arr.Display();
    Arr.Add(10);
    Arr.SortedInsert(3);
    Arr.Display();
    cout<<"\nThe sum of the elements is "<<Arr.RSum(Arr.length-1)<<endl;

    cout<<"\nThe Min element is "<<Arr.Min();
    cout<<"\nThe Max element is "<<Arr.Max()<<endl;
    // Arr.Delete(2);
    Arr.SwapReverse();
    Arr.Display();

    cout<<"Search for 3 is found at index "<<Arr.BSearch(3)<<endl;

    return 0;
}
