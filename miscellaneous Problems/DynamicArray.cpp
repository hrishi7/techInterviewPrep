#include<iostream>
using namespace std;
class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicArray(DynamicArray const &d)
    {
        //this->data = d.data;//shallow copy
        //deep copy is required
        this->data = new int[d.capacity];
        for(int i = 0; i< d.nextIndex; i++)
            this->data[i] = d.data[i];
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    void operator=(DynamicArray const &d)
    {
        //this->data = d.data;//shallow copy
        //deep copy is required
        this->data = new int[d.capacity];
        for(int i = 0; i< d.nextIndex; i++)
            this->data[i] = d.data[i];
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    void addElement(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for(int i= 0; i<capacity; i++)
            {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity *=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int get(int index) const
    {
        if(index < nextIndex)
            return data[index];
        else
            return -1;
    }
    void addAt(int index, int element)
    {
        if(index < nextIndex)
            data[index] = element;
        else if(index == nextIndex)
            addElement(element);
        else
            return;
    }
    void print() const
    {
        for(int i= 0; i<nextIndex; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};
