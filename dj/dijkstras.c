#include<stdio.h>
int a[100][100];
void dijkstras(int,int);
int known[100],path[100],cost[100];
int main()
{
 int i,j,x,n,c=0;
 printf("enter the no of nodes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  known[i]=0;
  path[i]=-1;
  cost[i]=100000000;
  }
 printf("enter the matrix of graph:");
 for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    {
     scanf("%d",&a[i][j]);
      }
 printf("enter the starting vertex:");
 scanf("%d",&x);
 dijkstras(x,n);
 for(i=0;i<n;i++)
 printf("\nmin cost(%d,%d)=%d\n",x,i,cost[i]);
 return 0;
 }
void dijkstras(int x,int n)
{
  int i,j,k;
  known[x]=1;
  cost[x]=0;
  for(i=0;i<n;i++)
    if(a[x][i]!=0)
    {
      cost[i]=a[x][i];
      path[i]=x;
      }

for(i=0;i<n-1;i++)
{
 for(j=0;j<n;j++)
  if(known[j]==0)
  {
   k=j;
   break;
   }
 for(;j<n;j++)
  if(known[j]==0 && cost[j]<cost[k])
   k=j;

 known[k]=1;
 for(j=0;j<n;j++)
 {
   if(known[j]==0)
   if(a[k][i]!=0 && (cost[k]+a[k][j])<cost[j])
   {
     cost[j]=cost[k]+a[k][j];
     path[j]=k;
     }
  }
 }
}
