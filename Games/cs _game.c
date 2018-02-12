#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
int s=0,y=0,z=0;
int main()
{int i,k,a[20];

    target();

{for(i=0;i<1000;i++)
{
    if(s==5)
        reload();
    else
    {
        k=getkey();
        if(k==72||k==80)
            move(k);
        else if(k==77)
        {
            shoot(a);
            s=s+1;
            a[z]=y;
            z=z+1;
        }
    }
    if(z==20)
	{
	gotoxy(0,y+8);
    printf("GAME OVER");
    break;
}
}
return 0;
}

}
int move(int k)
{
    if(k==72)
    {
        y=y-1;
        gotoxy(0,y);
        man1();
    }
    else
    {
        y=y+1;
        gotoxy(0,y);
        man1();
    }
}
int shoot(int *a)
{
    int i,b=0,k=(y+3)%2;
    gotoxy(0,y);
    man3();
    delay(200);
    gotoxy(0,y);
    man1();
    gotoxy(6,y+3);
    printf("%c%c",46,249);
    for(i=0;i<20;i++)
    {
        if(*(a+i)==y)
            b++;
    }
        if(b==0&&k==1)
        {
        	 if(((y+3)/2)%2==1)
                {
                    for(i=0;i<97;i++)
                    {
                        gotoxy(6+i,y+3);
                        printf(" %c%c",46,249);
                        delay(5);
                        
                    }
                    gotoxy(102,y+3);
                    printf("    ");
                    gotoxy(z+109,10);
                    printf("%c",65+y/2);
                    gotoxy(0,y);
                }
                else if(((y+3)/2)%2==0)
                {
                    for(i=0;i<99;i++)
                    {
                        gotoxy(6+i,y+3);
                        printf(" %c%c",46,249);
                        delay(5);
                    }
                    gotoxy(104,y+3);
                    printf("   ");
                    gotoxy(z+109,10);
                    printf("%c",65+y/2);
                    gotoxy(0,y);
                }
        }
        else
        
            {for(i=0;i<102;i++)
        {
            gotoxy(6+i,y+3);
            printf(" %c%c",46,249);
            delay(5);
        }
        gotoxy(107,y+3);
        printf("    ");
        gotoxy(z+109,10);
        printf(" ");
        gotoxy(0,y);
               
        
        }

    }


int reload()
{
    char r;
    gotoxy(0,y);
    printf("RELOAD ");
    scanf("%c",&r);
    if(r==r)
    {   gotoxy(0,y);
        man2();
        delay(1000);
        s=0;
        gotoxy(0,y);
        man1();
        
    }
    else
    {
      gotoxy(0,y);
        printf("         ");
        reload();    
    }
}
int target()
{
    int i,k;
    
    
    for(i=1;i<=26;i++)
    {
        k=i%2;
        if(k==0)
        {
            gotoxy(106,2*i+1);
            printf("%c",64+2*(i/2));
        }
        else if(k==1)
        {
            gotoxy(104,2*i+1);
            printf("%c",65+2*(i/2));
        }
    }
	gotoxy(60,58);
    for(i=0;i<40;i++)
    {printf("%c",1);
	}
	gotoxy(96,60);
	printf("DON'T KILL ME..");
    
    gotoxy(0,0);
    man1();
}
int man1()
{
    printf("        \n  %c    \n  %c    \n  %c%c%c \n  %c    \n  %c    \n %c %c  \n%c   %c   \n     ",153,179,195,196,193,179,30,47,92,47,92);
} 
int man2()
{
    printf("        \n  %c    \n  %c%c    \n  %c%c \n  %c    \n  %c    \n %c %c  \n%c   %c   \n     ",153,179,180,195,217,179,30,47,92,47,92);
}
int man3()
{
    printf("        \n  %c    \n  %c    \n  %c%c%c \n  %c    \n  %c    \n %c %c  \n%c   %c  \n     ",153,179,195,179,196,179,30,47,92,47,92);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void gotoxy(int col,int row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(h,position);
}
int getkey()
{
    int ch;
    ch=getch();
    if(ch==0)
    {
        ch=getch();
        return ch;
    }
    return ch;
}
