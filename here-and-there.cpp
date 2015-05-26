#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
//#include<conio.h>
#define N 10
#define M 120
#define swap(x,y,t) t=x;x=y;y=t;

void perm(int *a,int i,int n,int *k,int *b)
{
    int j,temp,m;
    *k=0;
    if (i==n)
    {
        for (b[*k]=0,j=0,m=1;j<=n;j++)
            {
                b[*k]+=a[n-j]*m;
                m*=10;
            }
            (*k)++;

    }
    else
        for (j=i;j<=n;j++)
    {
        swap(a[i],a[j],temp);
        perm(a,i+1,n,k,b);
        swap(a[i],a[j],temp);
    }
}

void random(int *a,int *n)
{
    int i;
    srand((unsigned)time(0));
    *n=rand()%2+4;
    for (i=0;i<*n;i++)
        a[i]=rand()%9+1;
}

int getdiff(int *b,int k,int *a,int n)
{
    int i,m=10,d,c[N],e;
    srand((unsigned)time(0));
    for(i=0;i<N;i++)
        a[i]=b[rand()%k];
    e=a[d=rand()%N];
    i=0;
    while (e)
    {
        c[i]=e%10;
        e/=m;
        i++;
    }
    e=c[i=rand()%N];
    do
    {
        c[i]=rand()%9+1;
    }
    while(e==c[i]);
    for (i=0,a[d]=0,m=1;i<n;i++)
    {
        a[d]+=m*c[i];
        m*=10;
    }
    return (d);
}

int main ()
{
    int i,j=1,n,a[N],b[M],k,d;
    while(j==1)
    {
    random(a,&n);
    perm(a,0,n-1,&k,b);
    d=getdiff(b,k,a,n);
    for(i=0;i<10;i++)
    printf("%d:%d\n",i+1,a[i]);
    printf("now find out the different number,just input numbers from one to ten:");
    scanf("%d",&i);
    if ((i-1)==d)
        printf("Correct");
    else
        printf("The correct answer seems to be %d, look carefully again.\n\n",d);
    //Sleep(3000);
    //system("cls");
    }
    return 0;
}
