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
    void Swap(int x, int y);
    void SwapReverse();
};
void DynamicArray::Create(){
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

void DynamicArray::Swap(int x, int y)
{
    int temp;
    temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

void DynamicArray::SwapReverse()
{
    int j;
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        Swap(i,j);
    }

}
int main()   //Main Function
{
    DynamicArray Arr;
    int choice = 0;
    cout<<"******ENTER YOUR OPTION******"<<endl<<endl;
    cout<<"1 Create dynamic array"<<endl;
    cout<<"2 Display dynamic array"<<endl;
    cout<<"3 Add element at the end"<<endl;
    cout<<"4 Add element at a particular index"<<endl;
    cout<<"5 Add element at sorted position"<<endl;
    cout<<"6 Delete element at a given index"<<endl;
    cout<<"7 Linear search for a key"<<endl;
    cout<<"8 Iterative Binary search for a key"<<endl;
    cout<<"9 Recursive Binary search for a key"<<endl;
    cout<<"10 Get element at a given index"<<endl;
    cout<<"11 Set the value at a given index"<<endl;
    cout<<"12 Get maximum element in the array"<<endl;
    cout<<"13 Get minimum element in the array"<<endl;
    cout<<"14 Get sum(Iterative) of elements in the array"<<endl;
    cout<<"15 Get sum(Recursive) of elements in the array"<<endl;
    cout<<"16 Get Average of elements in the array"<<endl;
    cout<<"17 Reverse the array the array"<<endl;
    cout<<"18 Swap elements in the array at given indices"<<endl;
    cout<<"29 Swap all consecutive elements in the array"<<endl;
    cout<<"20 ******EXIT******"<<endl;
    while(1){
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                Arr.Create();
                break;
            }
            case 2:{
                Arr.Display();
                break;
            }
            case 3:{
                int element;
                cout<<"Enter element to be inserted at the end: ";
                cin >> element;
                Arr.Add(element);
                break;
            }
            case 4:{
                int index,element;
                cout<<"Enter  index where you want to insert element: ";
                cin>>index;
                cout<<"Enter element you want to insert: ";
                cin>>element;
                Arr.Insert(index,element);
                break;
            }
            case 5:{
                int element;
                cout<<"Enter element to be inserted at the sorted position: ";
                cin >> element;
                Arr.SortedInsert(element);
                break;
            }
            case 6:{
                int index;
                cout<<"Enter index where you want to delete element: ";
                cin>>index;
                Arr.Delete(index);
                break;
            }
            case 7:{
                int key;
                cout<<"Enter key you want to search for(Linear search): ";
                cin>>key;
                int index = Arr.LSearch(key);
                if(index==-1){
                    cout<<"Element not found in array"<<endl;
                }else{
                    cout<<"Element found at index "<<index<<endl;
                }
                break;
            }
            case 8:{
                int key;
                cout<<"Enter key you want to search for(Iterative Binary search): ";
                cin>>key;
                int index = Arr.BSearch(key);
                if(index==-1){
                    cout<<"Element not found in array"<<endl;
                }else{
                    cout<<"Element found at index "<<index<<endl;
                }
                break;
            }
            case 9:{
                int key;
                cout<<"Enter key you want to search for(Recursive Binary search): ";
                cin>>key;
                int index = Arr.RBSearch(0,Arr.length,key);
                if(index==-1){
                    cout<<"Element not found in array"<<endl;
                }else{
                    cout<<"Element found at index "<<index<<endl;
                }
                break;
            }
            case 10:{
                int index;
                cout<<"Enter index from where you want to get value: ";
                cin>>index;
                int element = Arr.Get(index);
                if(index > Arr.length){
                    cout<<"Index out of range"<<endl;
                }else{
                    cout<<"Element at index "<<index<<" is "<<element<<endl;
                }
                break;
            }
            case 11:{
                int index,element;
                cout<<"Enter index where you want to insert value: ";
                cin >> index;
                cout<<"Enter value you want to insert at index "<<index<<": "<<endl;
                cin>>element;
                Arr.Set(index,element);
                break;
            }
            case 12:{
                int max = Arr.Max();
                cout<<"Maximum element in the array = "<<max<<endl;
                break;
            }
            case 13:{
                int min = Arr.Min();
                cout<<"Minimum element in the array = "<<min<<endl;
                break;
            }
            case 14:{
                int sum = Arr.Sum();
                cout<<"Sum of elements in the array(Iterative)= "<<sum<<endl;
                break;
            }
            case 15:{
                int sum = Arr.RSum(Arr.length);
                cout<<"Sum of elements in the array(Recursive)= "<<sum<<endl;
                break;
            }
            case 16:{
                int avg = Arr.Avg();
                cout<<"Average elements in the array = "<<avg<<endl;
                break;
            }
            case 17:{
                Arr.Reverse();
                break;
            }
            case 18:{
                int i1,i2;
                cout<<"Enter indices where you want to swap elements"<<endl;
                cin>>i1>>i2;
                Arr.Swap(i1,i2);
                break;
            }
            case 19:{
                Arr.SwapReverse();
                break;
            }
            case 20:{
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
