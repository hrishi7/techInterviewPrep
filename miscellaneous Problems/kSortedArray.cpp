#include<iostream>
using namespace std;

#include<queue>

void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;

    for(int i = 0; i<k; i++){
        pq.push(input[i]);
    }

    int j = 0;
    for(int i = k; i<n; i++){
        input[j] = pq.top();
        pq.pop();
        j++;
        pq.push(input[i]);
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int input[] = {12, 15, 7, 4, 9};
    kSortedArray(input, 5, 3);
    for(int i = 0; i<5; i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
