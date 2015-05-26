#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#define N 10
#define swap(x,y,t) t=x;x=y;y=t;

void perm(int *a,int i,int n,long *k)
{
    int j,temp;
    if (i==n)
    {
        for (j=0;j<=n;j++) printf("%d",a[j]); (*k)++; printf("\n");
    }
    else
        for (j=i;j<=n;j++)
    {
        swap(a[i],a[j],temp);
        perm(a,i+1,n,k);
        swap(a[i],a[j],temp);
    }
}

void random(int *t,int *n)
{
    int i;
    srand((unsigned)time(0));
    *n=rand()%3+2;
    t[0]=rand()%8+1;
    for (i=1;i<*n;i++)
        t[i]=rand()%9;
}

int main ()
{
    int i,n,a[N];long k=0;
    random(a,&n);
    perm(a,0,n-1,&k);
    printf("perm(%d)=%ld\n",n,k);
    return 0;
}
