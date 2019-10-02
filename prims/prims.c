#include<stdio.h>
int s[100][100],cost[100],path[100],known[100];
void prims(int,int);
int main()
{
 int i,j,x,n,c=0;
 printf("enter the no of nodes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   known[i]=0;
   path[i]=-1;
   cost[i]=10000000;
   }
printf("enter the matrix of graph:");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
 scanf("%d",&s[i][j]);
printf("enter starting vertex:");
scanf("%d",&x);
prims(x,n);
for(i=0;i<n;i++)
{
 c=c+cost[i];
 printf("\n min cost spanning tree %d",c);
 }
 return 0;
 }
 void prims(int x,int n)
 {
  int i,j,k;
  known[x]=1;
  cost[x]=0;
  for(i=0;i<n;i++)
  if(s[x][i]!=0)
  {
    cost[i]=s[x][i];
    path[i]=x;
    }
  for(i=0;i<n-1;i++)
  for(j=0;j<n;j++)
   if(known[j]==0)
   {
     k=j;
     break;
     }
  for(j=0;j<n;j++)
  {
    if(known[j]==0 &&cost[j]<cost[k])
    k=j;
    }
  known[k]==1;
  for(j=0;j<n;j++)
  if(known[j]==0)
  if(s[k][j]!=0 && s[k][j]<cost[j])
  {
   cost[j]=s[k][i];
   path[j]=k;
   }
 }
