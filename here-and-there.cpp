#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
#include<conio.h>
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
        a[i]=b[rand()%k];
    e=a[d=rand()%N];
    i=0;
    while (e)
    {
        c[i]=e%10;
        e/=m;
        i++;
    }
    e=c[i=rand()%n];
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

int char2int(char *c,int n)
{
    int i,m,a;
    for (i=n,a=0,m=1;i>=0;i--)
    {
        a+=m*(c[i]-48);
        m*=10;
    }
    return (a);
}

void g1 ()
{
    int i=0,j=1,n,a[N],b[M],k,d,coin;FILE *fp;char c[4],cmd;
    if ((fp=fopen("coin.txt","r+"))==NULL)
    {
        fp=fopen("coin.txt","w+");
        //fclose(fp);
        fp=fopen("coin.txt","r+");
    }
    c[i]=fgetc(fp);
    while (!feof(fp))
    {
        i++;
        c[i]=fgetc(fp);
    }
    if (i==0)
        coin=0;
    else
        coin=char2int(c,i-1);
    fseek(fp,0,0);
    fprintf(fp,"%d",coin+1);//bug1：第一次使用fprint无效，故在这里处理一下
    while(j==1)
    {
    k=0;
    printf("Your coins:%d\n",coin);
    random(a,&n);
    perm(a,0,n-1,&k,b);
    d=getdiff(b,k,a,n);
    for(i=0;i<10;i++)
    printf("%d:%d\n",i,a[i]);
    printf("Now find out the different number,just input numbers from one to ten:",d);//直接输出正确答案测试用
    scanf("%c",&cmd);
    if ((cmd>='0')&(cmd<='9'))
    {
        if ((cmd-48)==d)
        {
            printf("Correct\n\n");
            coin++;
            fseek(fp,0,0);//bug4:可以只输入文件一次，但是必须两次fseek；bug5:在while j==1的循环体中没有调用fprint但是文件依然被改写，但是当测试数据为6时重新启动程序只有3的金币，使用下面的fprintf则恢复正常
            //printf("%d",ftell(fp));
            fprintf(fp,"%d",coin+1);//bug2:直接用coin始终少1
            Sleep(500);
        }
        else
        {
            printf("The correct answer seems to be %d, look carefully again.\n\n",d);
            Sleep(3000);
        }
    }
    else
    {
        switch(cmd)
        {
        case('e'):{j=0;break;}
        default:;
        }
    }
    system("cls");
    }
    fclose(fp);
}
int main()
{
    g1();
    return 0;
}
