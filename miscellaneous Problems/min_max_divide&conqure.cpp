#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_num=INT_MIN,min_num= INT_MAX;

void maxmin(int a[],int l, int u){
    if(l==u)
        max_num = a[l];
        min_num = a[l];
    else{
        if(l == u - 1){
            if(a[l] < a[u]){
                max_num = a[u];
                min_num = a[l];
            }
            else{
                max_num = a[l];
                min_num = a[u];
            }
        }
        else{
            int mid = (l + u)/2;
            maxmin(a,l,mid);
            int max1 = max_num;
            int min1 = min_num;
            maxmin(a, mid + 1, u);
            if(max_num < max1)
                max_num = max1;
            if(min_num > min1)
                min_num = min1;
        }
    }
}

int main(){
    int a[] = {5,4,3,2,1};
    maxmin(a,0,4);
    cout<<max_num<<endl;
    cout<<min_num<<endl;

}
