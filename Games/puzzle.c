#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int getkey();
int display(int a[][4],int);
int open();
int mid();
int end();
int smid();


int main()
{int a[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0};
display(a,4);
int i,j,key,m,n;
do
{for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        if(a[i][j]==0)
        {
            m=i;
            n=j;
        }
    }
}

key=getkey();

system("cls");
switch (key)
{
case 72:
    {
        if(m==3)
            printf("Retry\n");
        else
        {
            a[m][n]=a[m+1][n];
            a[m+1][n]=0;
        }
        break;
    }
case 80:
    {
        if(m==0)
            printf("Retry\n");
        else
        {
            a[m][n]=a[m-1][n];
            a[m-1][n]=0;
        }
        break;
    }
case 75:
    {
        if(n==3)
        printf("Retry\n");
        else
        {
            a[m][n]=a[m][n+1];
            a[m][n+1]=0;
        }
        break;
    }
case 77:
    {
        if(n==0)
            printf("Retry\n");
        else
        {
            a[m][n]=a[m][n-1];
            a[m][n-1]=0;
        }
        break;
    }

}


display(a,4);
}while(a[0][0]!=1||a[0][1]!=2||a[0][2]!=3||a[0][3]!=4||a[1][0]!=5||a[1][1]!=6||a[1][2]!=7||a[1][3]!=8||a[2][0]!=9||a[2][1]!=10||a[2][2]!=11||a[2][3]!=12||a[3][0]!=13||a[3][1]!=14||a[3][2]!=15||a[3][3]==0);

}
int display(int a[][4],int n)
{
    int i,k;
    for(k=1;k<=17;k++)
    {
        if(k==1)
            open();
        else if(k==17)
            end();
        else if(k==5||k==9||k==13)
            mid();
        else if(k==2||k==4||k==6||k==8||k==10||k==12||k==14||k==16)
                smid();
        else
        {
            for(i=0;i<n;i++)
            {
                if(a[k/4][i]==0)
                    printf("%c   ",179);
                else if(a[k/4][i]==10||a[k/4][i]==11||a[k/4][i]==12||a[k/4][i]==13||a[k/4][i]==14||a[k/4][i]==15)
                    printf("%c %d",179,a[k/4][i]);
                else
                    printf("%c %d ",179,a[k/4][i]);

            }
            printf("%c\n",179);
        }
    }
}
int open()
{
    int i;
    printf("%c%c",218,196);
    for(i=0;i<3;i++)
    {
        printf("%c%c%c%c",196,196,194,196);

    }
    printf("%c%c%c\n",196,196,191);
    return 0;
}
int mid()
{
    int i;
    printf("%c%c",195,196);
    for(i=0;i<3;i++)
    {
        printf("%c%c%c%c",196,196,197,196);
    }
    printf("%c%c%c\n",196,196,180);
}

int end()
{
    int i;
    printf("%c%c",192,196);
    for(i=0;i<3;i++)
    {
        printf("%c%c%c%c",196,196,193,196);
    }
    printf("%c%c%c\n",196,196,217);
    return 0;
}
int smid()
{
    int i;
    for(i=0;i<4;i++)
        printf("%c   ",179);
    printf("%c \n",179);
}

int getkey()
{int ch;
ch=getch();
if(ch==0)
{ch=getch();

return ch;
}

return ch;
}
