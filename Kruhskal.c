#include<stdio.h>

int parent[9],n=9;
int cost[9][9]={
                {0 ,10, 12, 0, 0, 0, 0, 0, 0},
{10, 0, 9, 8, 0, 0, 0, 0, 0},
{12, 9, 0, 0, 3, 1, 0, 0, 0},
{0, 8, 0, 0, 4, 0, 8, 5, 0},
{0, 0, 3, 4, 0, 3, 0, 0, 0},
{0, 0, 1, 0, 3, 0, 0, 6, 0},
{0, 0, 0, 8, 0, 0, 0, 9, 2},
{0, 0, 0, 5, 0, 6, 9, 0, 11},
{0, 0, 0, 0, 0, 0, 2, 11, 0}
                };

int find(int);
int uni(int,int);
void kruskal();

void kruskal()
{
int min,mincost=0,ne=0,i,j,u,v,a,b;
    for(i=0;i<n;i++)
    {
         parent[i]=0;
    }

    while(ne<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(cost[i][j]==0)
                {
                    cost[i][j]=999;
                }
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    u=a=i;
                    v=b=j;
                }
            }

        u=find(u);
        v=find(v);

        if(u!=v)
        {
            ne=ne+1;
            mincost=mincost+min;
            printf("\nedge %d --> %d is = %d", a+1,b+1,min);
            printf("\t%d %d",u,v);
            uni(u,v);
        }
        cost[a][b]=cost[b][a]=999;
    }
 printf("\n Min cost: %d", mincost);
}

int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}

int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}


main(void)
{
    int i,j;

    printf("\n The matrix is:-\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d\t",cost[i][j]);
      printf("\n");
    }
 kruskal();
}
