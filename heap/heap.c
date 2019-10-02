#include<stdio.h>
void insert(void);
void deletemin(void);
void swap(int,int);
int a[100],n=0;
int main()
{
    int c,i;
    while(1)
    {
        printf("\n1.insert\n2.deletemin\n3.print\n4.exit\nenter your choise");
        scanf("%d",&c);
        if(c==1)
            insert();
        else if(c==2)
            deletemin();
        else if(c==3)
            for(i=0; i<n; i++)
                printf("%d ",a[i]);
        else
            break;
    }
    return 0;
}

void insert()
{
    int i,v,t,j;
    printf("enter the element:");
    scanf("%d",&v);
    i=n;
    a[n++]=v;
    while(i>0)
    {
        j=(i-1)/2;
        if(a[i]<a[j])
        {
            swap(i,j);
            i=j;
        }
        else
            break;
    }
}

void deletemin()
{
    int i=0,v,j,k;
    if(n==0)
    {
        printf("Heap is empty");
        return;
    }
    v=a[0];
    printf("the deleted element is %d",v);
    a[0]=a[--n];
    while(2*i+1<n)
    {
        j=2*i+1;
        k=j+1;
        if((a[i]>a[j])&&(a[k]>=a[j]))
        {
            swap(i,j);
            i=j;
        }
        else if(a[i]>a[k] && a[j]>a[k])
        {
            swap(i,k);
            i=k;
        }
        else
            break;
    }
    j=2*i+1;
    if(j<n)
        if(a[j]<a[i])
            swap(i,j);

}

void swap(int i,int j)
{
    int t;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
}
