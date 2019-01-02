#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    //Write your code here
  int n;
  cin>>n;
  int* arr = new int[n];
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr + n, greater<int>());
  long int ans = 0;
  for(int i = 0; i<n; i++){
    ans +=pow(2,i) * arr[i];
  }
  cout<<ans<<endl;
    return 0;
}
