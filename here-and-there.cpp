#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#define N 10
#define M 120
#define swap(x,y,t) t=x;x=y;y=t;

void perm(int *a,int i,int n,int *k,int *b)
{
    int j,temp,m;
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
        a[i]=b[rand()%k];//从b中任选10个数
    e=a[d=rand()%N];//决定要改变的那个数，d用于保存下标
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
    int i,n,a[N],b[M],k=0,d;
    random(a,&n);
    perm(a,0,n-1,&k,b);
    printf("perm(%d)=%d\n",n,k);
    d=getdiff(b,k,a,n);
    for(i=0;i<10;i++)
    printf("%d:%d\n",i+1,a[i]);
    printf("now find out the different number,just input numbers from one to ten:");
    scanf("%d",&i);
    if ((i-1)==d)
        printf("Correct");
    else
        printf("The correct answer seems to be %d, look carefully again.",d);
    return 0;
}
