#include<iostream>
#include<climits>

using namespace std;

template <typename T>
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;
public:
    StackUsingArray(){
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        if(nextIndex == 0)
            return true;
        else
            return false;
    }
    void push(T element){
        if(nextIndex == capacity){
            //cout<<"stack FULL";
            //return;
            T *newData = new T[capacity * 2];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stack Empty";
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"stack Empty";
            return 0;
        }
        return data[nextIndex - 1];
    }
};
