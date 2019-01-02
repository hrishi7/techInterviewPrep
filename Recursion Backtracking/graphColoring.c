#include<stdio.h>
#include<conio.h>
int x[50],g[50][50],n,i,j,m;
    void next_value(int k)
    {
        while(1)
        {
            x[k]=(x[k]+1)%(m+1);
            if(x[k]==0)//if 5%5== 0 then it's done the coloring for all vertices now simply return
                return;
            for(j=1;j<=n;j++)
            {
                if(g[k][j]!=0&&(x[k]==x[j]))//checking for all adjacent that color is matching or not if matching
                    break;//then try for next color value break from inner for loop and going to outer while

            }
            if(j==n+1)//it works when checking for all adjacent coloring is done and now try for next vertex
                return;
        }
    }
    void coloring(int k)
    {
        do
        {
            next_value(k);
            if(x[k]==0)
                return;
            if(k==n)
            {
                for(i=1;i<=n;i++)
                    printf("vertex %d = color No. %d\t",i,x[i]);
                printf("\n");
            }
            else
                coloring(k+1);
        }while(k<n+1);
    }

    void main()
    {
        int e,k,l;
        printf("Enter no. of vertices : ");
        scanf("%d",&n);
        printf("Enter no. of edges : ");
        scanf("%d",&e);
        m=n-1;
        printf("\nThe maximum possible colours that can be assigned are: %d\n",m);
        for(i=0;i<=n;i++){//initialization of graph matrix
            for(j=0;j<=n;j++){
                g[i][j]=0;
            }
        }
        printf("Enter u and v of an edge\n");
        for(i=1;i<=e;i++)//setting 1 at the edges of the graph matrix g[i][j]
        {
            printf("\nfor egde %d\n",i);
            scanf(" %d %d",&k,&l);
            g[k][l]=1;
            g[l][k]=1;
        }
        for(i=0;i<=n;i++)
            x[i]=0;
        printf("\nThe colouring possibilities are:\n");
        coloring(1);
        getch();
    }
