
#include<iostream>
using namespace std;

long long mergeAndGetInversionCount(int arr[],int l, int m, int r){

    int i=l, j = m, k=0;
    int temp[r - l + 1];
    long long  count = 0;
    while (i < m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += m - i;
        }
    }
    while (i < m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }
    for(int i = l,k = 0; i<= r; i++,k++){
        arr[i] = temp[k];
    }
    return count;
}


long long getInversionCount(int a[], int l, int r){
    long long count = 0;
    if(r > l){
    int mid = (l + r)/2;
    long long leftCount = getInversionCount(a, l, mid);
    long long rightCount = getInversionCount(a, mid + 1, r);
    long long myCount = mergeAndGetInversionCount(a,l,mid + 1,r);

    return myCount + rightCount + leftCount;
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i< n; i++){
        cin>>a[i];
    }
    cout<<getInversionCount(a,0,n - 1)<<endl;
    return 0;
}
