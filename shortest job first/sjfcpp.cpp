#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    cout<<"Enter number of process:";
    cin>>n;

    int bt[n],p[n],wt[n],tat[n];

    cout<<"Enter Burst Time:"<<endl;
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        cin>>bt[i];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process will be zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time"<<endl;;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\np%d\t\t  %d\t\t    %d\t\t\t%d"<<p[i]<<bt[i]<<wt[i]<<tat[i];
    }

    avg_tat=(float)total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time=%f"<<avg_wt;
    cout<<"\nAverage Turnaround Time=%f"<<avg_tat;

    return 0;
}

