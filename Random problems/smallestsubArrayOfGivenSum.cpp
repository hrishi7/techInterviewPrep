#include <iostream>
using namespace std;


int getLengthSmallestSubArray ( int* a, int n, int x){
    int s = 0, e = 0, min_length = n + 1, current_sum = 0;
    while(e < n){
        while( current_sum < x && e < n){
            current_sum += a[e++];
        }
        while( current_sum > x && s < n){
            if(min_length > (e - s)){
                min_length = e - s;
            }
            current_sum -= a[s++];
        }
    }
    return min_length;
}

int main() {
    int n,x;
    cin>>n;
	int *a = new int[n];
	for(int i = 0; i<n; i++){
	    cin>>a[i];
	}
	cin>>x;
	cout<<getLengthSmallestSubArray(a,n,x);
	return 0;
}
