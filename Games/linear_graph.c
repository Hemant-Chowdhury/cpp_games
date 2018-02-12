#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void gotoxy(int col,int row);

int main()
{
    int num;
    printf("choose the line equation 1:y=mx+c or 2:x=ny+t :");
    scanf("%d",&num);
    if(num==1)
      yaxis();
    else if(num==2)
	  xaxis();
	else
	   printf("Invalid input");
	   getch();
	return 0; 
}
void yaxis()
   {int m,c,i;
    printf("Enter the slope(m) and intercept(c):");
    scanf("%d %d",&m,&c);
    system("cls");
    axis();
        for(i=0;i<67;i++)
        {     
        if(c>-34&&c<34)
            {gotoxy(i*3,33-(m*(i-33)+c));
             printf("%c",46);
            }
           
        }
        gotoxy(0,69);
        printf("y=%dx+%d\n",m,c);
    }
void xaxis()
{int n,i,t;
printf("Enter n and t of x=ny+t :");
scanf("%d %d",&n,&t);
system("cls");
axis();

for(i=0;i<67;i++)
{if(t>-34&&t<34)
{gotoxy((33+(n*(33-i)+t))*3,i);
printf("%c",46);
}
}
gotoxy(0,69);
printf("x=%dy+%d",n,t);
		}        
    

void axis(void)
{
    int i,n;
    for(i=0;i<67;i++)
    {
        gotoxy(i*3,33);
        printf("%c%c%c",197,196,196);
        gotoxy(i*3,34);
        printf("%d",-33+i);
    }
    for(i=0;i<67;i++)
    {
        gotoxy(33*3,i);
        printf("%c",197);
        gotoxy(32*3,i);
        if(n!=33)
            printf("%d",33-i);
    }
}
void gotoxy(int col,int row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(h,position);
}
