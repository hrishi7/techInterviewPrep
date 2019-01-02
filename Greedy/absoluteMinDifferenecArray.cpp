#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {
  sort(arr, arr + n);
  int min = INT_MAX;
  for(int i = 0; i<n; i++){
    int d = abs(arr[i+1] - arr[i]);
    if(min > d){
      min = d;
    }
  }
  return min;
}


int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	cout<< minAbsoluteDiff(input,size) << endl;

	return 0;

}
