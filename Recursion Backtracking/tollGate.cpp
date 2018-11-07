#include <bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

void leftrotateOnce( int *menarray,int total)
{
  for(int j=0; j<3; j++)
  {
    if(total>0)
    {
      if(total>=menarray[j])
      {
        total-=menarray[j];
        menarray[j]=0;
      }
      else if(total<menarray[j])
      {
        menarray[j]-=total;
        total=0;
      }
    }
  }
  menarray[0]=menarray[1];
  menarray[1]=menarray[2];
  menarray[2]=0;
}

int getMinCost(int i, int n,int *cost, int *men, int *menarray){
  int count=0;
  if(i == n){
    return 0;
  }
  //pay the money and go forward to next gate
  int option1 = cost[i]+getMinCost(i + 1, n, cost, men, menarray);
  //buying the men
  menarray[2] += men[i];
  int option2 = (2 * cost[i])+getMinCost(i + 1, n, cost, men, menarray);
  menarray[2] -= men[i];

  //fight with toll mens
  int option3 = INT_MAX;
  //temp array of menarray of my soldiers
  int temparray[3];
  for(int j=0; j<3; j++)
  {
      temparray[j]=menarray[j];
      count+=menarray[j];
  }
  //checking if my soldier count >= men[i] toll men
  if(count>=men[i])
  {
      leftrotateOnce(temparray,men[i]);
      option3=getMinCost(i+1,n,cost,men,temparray);
  }
  else
      option3=max(option1,option2);
  return min(option1,min(option2,option3));
}

int main()
{
  int n;
  cin>>n;
  int *men = new int[n];
  int *cost = new int[n];
  int *menarray = new int[3];
  for(int i = 0; i<3; i++){
    menarray[i] = 0;
  }
  for(int i = 0; i < n; i++){
    cin>>men[i]>>cost[i];
  }
  int ans = getMinCost(0,n,cost,men,menarray);
  cout<<ans<<endl;
  return 0;
}
