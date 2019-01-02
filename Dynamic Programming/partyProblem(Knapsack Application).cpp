#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int w[101], val[101], dp[101][501];
int main()
{
    int i, j, W, n, ans;
    while(1)
    {
    	cin>>W>>n;
    	if(W==0&&n==0)
    	break;
	    w[0]=0;
	    val[0]=0;
	    for(i=0;i<n;i++)
	        scanf("%d %d", &w[i+1], &val[i+1]);
	    for(i=0;i<=n;i++)
	        dp[i][0]=0;
	    for(j=0;j<=W;j++)
	        dp[0][j]=0;
	    for(i=1;i<=n;i++)
	    for(j=1;j<=W;j++)
	    {//Every time i am checking if max weight is j
	        if(w[i]>j)
	        {
	            dp[i][j]=dp[i-1][j];//if weight of the element is more than the required weight ..just give value of previous item
	        }
	        else
	        dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+val[i]);
	    }
	    ans=W;
	    for(i=0;i<W;i++)
	    {
	        if(dp[n][i]==dp[n][W])
	        {
	            ans=i;
	            break;
	        }
	    }
	    printf("%d %d\n", ans, dp[n][W]);
	}
}
